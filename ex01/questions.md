1. how to pass function as paramter in c++
https://www.geeksforgeeks.org/cpp/passing-a-function-as-a-parameter-in-cpp/

2. (void *) ? 

核心原因 (Why?)

1. 参数类型不匹配 (void* 错误)：
从报错信息可以看到，你的 iter 函数模板声明长这样：
template<class T> void iter(T*, std::size_t, void*)
你把接收第三个参数的类型写成了 void*（万能数据指针）。
2. C++ 的类型安全限制：
void* 只能用来指向数据（比如 int*, char* 等），而不能用来指向代码/函数。编译器无法把一个函数指针（如 add<int>）自动打包转换成 void*。这就是为什么编译器报错说：
cannot convert 'add<int>' ... to type 'void*'

3. `void (*fn)(T&)`
在 C++ 中，函数本身是一段编译好的机器码，存放在内存的代码区。你无法把一整段代码活生生地塞进另一个函数的参数里。
你能传递的，只有这个函数在内存中的首地址（也就是函数指针）。
• void (*fn)(T&)：这里的 * 明确告诉编译器，fn 是一个指针变量，它负责存储外面传进来的那个函数的内存地址。
• 有了这个 fn 指针，你在 iter 内部写 fn(arr[i]) 时，程序才能顺着这个地址找到你的 add 函数去执行。
