/*完成下述代码中注释的部分，使程序能读取物品讯息，检查合法性，并在合法时输出总重。*/

/*注意：
1. 不能修改其他部分。
2. 不能有内存泄漏。*/

#include <iostream>
#include <vector>

class Item {
public:
    /* 编写构造函数、析构函数 */

    virtual int GetWeight() const {
        return weight_;
    }

    virtual bool IsValid() const {
        return true;
    }

private:
   int weight_;
};

class Bag : public Item {
public:
   /* 编写构造函数、析构函数及其他函数 */

private:
    std::vector<Item*> items_;
    int maxWeight_;
};

Bag* Parse() {
    /* 编写读入数据的代码 */
}

int main() {
    Bag* root = Parse();

    if (root->IsValid())
        std::cout << root->GetWeight() << std::endl;
    else
        std::cout << "invalid";

    delete root;
}