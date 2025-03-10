#include <iostream>
#include <cstring>
#include "sequenceList.h"
using namespace std;


template<class ElementType>
void LinearList<ElementType>::
DisplayElementLinearList(ElementType result) {
    cout << result.number <<"\t";
    cout << result.name << "\t";
    cout << result.sex << "\t";
    cout << result.age << "\t";
    cout << result.place << endl;
}

template<class ElementType>
void LinearList<ElementType>::
DisplayLinearList(LinearList<ElementType> &AppList) // 这里也可以不传参，直接用this
{
    ElementType result;
    cout << "\t\tnumber\tname\tsex\tage\tplace" <<endl;
    cout << "\t\t----- \t---\t ---\t---\t----" << endl;
    for (int i=0; i<AppList.LengthLinearList(); i++) {
        AppList.GetElementLinearList(i,result);
        cout << "ELEMENT- " << i+1 <<":\t";
        DisplayElementLinearList(result);
    }
    cout << endl;
}

int main()
{
    int MaxListSize = 20;
    int i,k,choice;
    Student newvalue,result;
    char number[][8] = {"10001","10002","10003","10004"};
    char name[][8] = {"stu1","stu2","stu3","stu4"};
    char sex[][8] = {"m","w","m","w"};
    char place[][8] ={"www1","www2","www3","www4"};
    int age[] = {101,102,103,104};
    LinearList<Student> AppList(MaxListSize);
    for (int i=0; i<sizeof(number)/sizeof(number[0]);i++) {
        strcpy(newvalue.number, number[i]);
        strcpy(newvalue.name, name[i]);
        strcpy(newvalue.sex, sex[i]);
        newvalue.age = age[i];
        strcpy(newvalue.place, place[i]);
        AppList.InsertElementLinearList(i,newvalue);
    }
    while(true)
    {
        cout <<"\t顺序存储线性表顺序存储的运算" <<endl;
        cout << "*****************************" <<endl;
        cout << "\t0---退出" <<endl;
        cout << "\t1---输出顺序表中的所有元素" <<endl;
        cout << "\t2---在顺序表中查找第k个元素(k从0开始)" <<endl;
        cout << "\t3---查找关键字为searchkey的元素" <<endl;
        cout << "\t4---插入新元素到第k个元素后面" <<endl;
        cout << "\t5---在顺序表中删除第k个元素" <<endl;
        cout << "请选择处理功能："; cin >> choice;
        system("clear");
        cout <<endl<<"此操作前顺序表状态:"<<endl;
        AppList.DisplayLinearList(AppList);
        switch(choice) {
            case 0:
            {
                system("clear");
                return 0;
            }
            case 1:
            {
                cout << "输出顺序表中的所有元素"<<endl;
                AppList.DisplayLinearList(AppList);
                break;
            }
            case 2:
            {
                cout << "在顺序表中查找第k个元素" <<endl;
                cout <<"查找第几个元素？"; cin >> k;
                cout << "查找结果如下" << endl;
                if (AppList.GetElementLinearList(k-1,result)) {
                    cout << "ELEMENT-"<<k<< ":";
                    AppList.DisplayElementLinearList(result);
                } else {
                    cout << "ERROR k值的范围不对!无此元素!"<<endl;
                }
                break;
            }
            case 3:
            {
                cout << "查找关键字为searchkey的元素" <<endl;
                char searchkey[8];
                cout << "请输入查找关键字searchkey的值:"<<endl;
                cin >> searchkey;
                k = AppList.SearchElementLinearList(searchkey);
                cout <<endl<<"查找结果如下：" <<endl;
                if (k != -1) {
                    AppList.GetElementLinearList(k,result);
                    cout << "ELEMENT-"<<k+1<<":";
                    AppList.DisplayElementLinearList(result);
                } else
                    cout <<"ERROR:无此关键字的元素" <<endl;
                break;
            }
            case 4:
            {
                cout << "线性表中插入新元素到第k个元素后面" <<endl;
                cout << "插入到第几个元素后面？"; cin >> k;
                cout << "输入要插入的各元素的值:" << endl;
                cout << "学号："; cin>>newvalue.number;
                cout << endl << "姓名："; cin >> newvalue.name;
                cout << endl << "性别："; cin >> newvalue.sex;
                cout << endl << "年龄："; cin >> newvalue.age;
                cout << endl << "住址：" << endl; cin >> newvalue.place;
                if (AppList.InsertElementLinearList(k,newvalue))
                {
                    cout << "插入元素到第" << k<<"个元素后的线性表结果："<<endl;
                    AppList.DisplayLinearList(AppList);
                } else
                    cout << "ERROR:找不到插入点,k值范围不对或空间不足!" <<endl;
                break; 
            }
            case 5:
            {
                cout << "在线性表中删除第k个元素"<<endl;
                cout << "删除第几个元素？"; cin >> k;
                if (AppList.DeleteElementLinearList(k-1))
                {
                    cout << "输出元素后的线性表结果如下：" <<endl;
                    AppList.DisplayLinearList(AppList);
                } else
                    cout << "ERROR:找不到要删除的节点,k值的范围不对" <<endl;
                break;
            }
        }
        cout << "顺序表的长度：" << AppList.LengthLinearList() << endl;
        system("read -n 1 -s -r -p \"Press any key to continue...\"");     // 在windows中这条命令替换为 pause
        system("clear");
    }
    return 0;
}
