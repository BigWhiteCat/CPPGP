## 神奇的Trait

首先，介绍traits前，回味一下C++的模板及应用，如果你脑海里浮现出的只是为实现一些函数或类的重用的简单模板应用，那我要告诉你，你out了。最近在整理一些模板的应用方式，有时间的话会写出来分享给大家，本文不会去详细讨论traits以外的模板的各种高级应用。
那么，言归正传，什么是traits？其实它并不是一个新的概念，上个世纪90年代中期就已经被提出，只是到了这个世纪才在各个C++库中被广泛使用，而我也是在这个概念诞生十多年后才接触到它。

>C++之父Bjarne Stroustrup对traits有如下的描述：
>Think of a trait as a small object whose main purpose is to carry 
>information used by another object or algorithm to determine "policy" or
>"implementation details".

我不知道官方或一些书上是如何去解释traits的，我的理解是：
 当函数，类或者一些封装的通用算法中的某些部分会因为数据类型不同而导致处理或逻辑不同（而我们又不希望因为数据类型的差异而修改算法本身的封装时），traits会是一种很好的解决方案。

本以为能很简单的描述它，谁知道还是用了如此长的句子才说明清楚，相当的惭愧。大家只要有个大概的概念就ok了，甚至即使完全没概念也没关系，下面会通过实际代码来说明。

先看这样一个例子。如果有一个模板类Test：

```c++
template <typename T>
class Test {
     ......
};
```

假设有这样的需求，类Test中的某部分处理会随着类型T的不同而会有所不同，比如希望判断T是否为指针类型，当T为指针类型时的处理有别于非指针类型，怎么做？
模板里再加个参数，如下：

```c++
template <typename T, bool isPointer>
class Test {
     ......// can use isPointer to judge whether T is a pointer
};
```

然后用户通过多传一个模板类型来告诉Test类当前T是否为指针。(Test<int*, true>)
很抱歉，所有的正常点的用户都会抱怨这样的封装，因为用户不理解为什么要让他们去关心自己的模板类型是否为指针，既然是Test类本身的逻辑，为什么麻烦用户呢？
由于我们很难去限制用户在使用模板类时是使用指针还是基本数据类型还是自定义类型，而用常规方法也没有很好的方法去判断当前的T的类型。traits怎么做呢？
定义traits结构：

```C++
template <typename T>
struct TraitsHelper {
     static const bool isPointer = false;
};
 
template <typename T>
struct TraitsHelper<T *> {
     static const bool isPointer = true;
};
```

也许你会很困惑，结构体里就一个静态常量，没有任何方法和成员变量，有什么用呢？解释一下，第一个结构体的功能是定义所有TraitsHelper中isPointer的默认值都是false，而第二个结构体的功能是当模板类型T为指针时，isPointer的值为true。也就是说我们可以如下来判断当前类型：
TraitsHelper<int>::isPointer值为false， 可以得出当前类型int非指针类型
TraitsHelper<int*>::isPointer值为true， 可以得出当前类型int*为指针类型
也许看到这里部分人会认为我简直是在说废话，请再自己品味下，这样是否就可以在上面Test类的定义中直接使用TraitsHelper<T>::isPointer来判断当前T的类型了。

```c++
if (TraitsHelper<T>::isPointer)
     ......
else
     ......
```

再看第二个例子：
还是一个模板类Test：

```C++
template <typename T>
class Test {
public:
     int Compute(int d);
private:
     T mData;
};
```

它有一个Compute方法来做一些计算，具有int型的参数并返回int型的值。
现在需求变了，需要在T为int类型时，Compute方法的参数为int，返回类型也为int，当T为float时，Compute方法的参数为float，返回类型为int，而当T为其他类型，Compute方法的参数为T，返回类型也为T，怎么做呢？还是用traits的方式思考下。

```c++
template <typename T>
struct TraitsHelper {
     typedef T ret_type;
     typedef T par_type;
};
 
template <>
struct TraitsHelper<int> {
     typedef int ret_type;
     typedef int par_type;
};
 
template <>
struct TraitsHelper<float> {
     typedef float ret_type;
     typedef int par_type;
};
```

然后我们再把Test类也更新下：

```c++
template <typename T>
class Test {
public:
     TraitsHelper<T>::ret_type Compute(TraitsHelper<T>::par_type d);
private:
     T mData;
};
```

可见，我们把因类型不同而引起的变化隔离在了Test类以外，对用户而言完全不需要去关心这些逻辑，他们甚至不需要知道我们是否使用了traits来解决了这个问题。
到这里，再让我们回过来取品味下开始我说的那句话：
当函数，类或者一些封装的通用算法中的某些部分会因为数据类型不同而导致处理或逻辑不同时，traits会是一种很好的解决方案。