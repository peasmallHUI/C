# C++ primer plus
## 第四章
- `string`
    >可以直接使用加减赋值等变量操作
    ```c++
    string str1,str2,str3;
    str1 = "test1";
    str2 = "test2";
    str3 = str1 + str2;  //字符串直接相加
    str2 += str1;
    ```
- `new` `delete`
    >利用`new`创建动态变量或数组为其分配内存，`delete`来删除`new`创建的内存
    ```c++
    type_name *point_name = new type_name [num_elements];
    delete [] point_name; 
    ```
