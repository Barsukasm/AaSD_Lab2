#include <iostream>
#include <time.h>
#include <math.h>
#include "BST-tree.h"

using namespace std;

long distIt(int min,int max){
    return (min+(rand()<<16|rand())%max);
}

long distKey(){
    return ((rand()<<16|rand()));
}

void testComplexity(int number, int min, int max){
    BSTtree<int, int > test;
    test.clear();
    srand((unsigned int)time(NULL));

    int err=0;
    for(int i=0;i<number;i++){
        test.add(distIt(min,max),distIt(min,max));
    }
    cout<<"tree created"<<endl;

    long long d=0, ins=0, f=0;
    for(int i=0;i<number;i++){
        try{
            test.remove(distIt(min,max));
            d+=test.getOperations();

            test.add(distIt(min,max), distIt(min,max));
            ins+=test.getOperations();

            test.read(distIt(min,max));
            f+=test.getOperations();
        }catch (int code){
            if(code==KEY_DOES_NOT_EXIST) {
                err++;
                f+=test.getOperations();
            }
        }
    }


    cout<<"Time complexity"<<endl;
    cout<<"Delete: "<<endl;
    cout<<"Theoretical: "<<(float)((log(number)/log(2)))<<" Practical: "<<(float)d/number<<endl;
    cout<<"Insert: "<<endl;
    cout<<"Theoretical: "<<(float)((log(number)/log(2)))<<" Practical: "<<(float)ins/number<<endl;
    cout<<"Find: "<<endl;
    cout<<"Theoretical: "<<(float)((log(number)/log(2)))<<" Practical: "<<(float)f/number<<" Errors: "<<err<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"List size: "<< test.getSize()<<endl;
}

void showMenu(){
    cout << endl;

    cout << "1. Watch tree" << endl;
    cout << "2. Clear tree" << endl;
    cout << "3. Empty check" << endl;
    cout << "4. Show value by key" << endl;
    cout << "5. Change value by key" << endl;
    cout << "6. Add value by key" << endl;
    cout << "7. Delete value by key" << endl;
    cout << "8. Walk" << endl;
    cout << "9. External path length" << endl;
    cout << "10. Tree size" << endl;
    cout << "11. Iterator to first key position" << endl;
    cout << "12. Iterator to last key position" << endl;
    cout << "13. Change value at iterator's position" << endl;
    cout << "14. Show value at iterator's position" << endl;
    cout << "15. Next key" << endl;
    cout << "16. Prev key" << endl;
    cout << "17. Test" << endl;
    cout << "0. Exit" << endl;
}

int main() {
    BSTtree<int,int> tree;
    BSTtree<int ,int >::Iterator iter(tree);

    showMenu();

    bool exit = false;
    int com;
    while (!exit){
        cout<<"input command:";
        cin>>com;
        cout<< endl;
        try{
            switch (com){
                case 0: exit= true;
                    break;
                default: cout << "No such command exist"<<endl;
                    break;

                case 1:{
                    tree.print();
                    break;
                }

                case 2:{
                    tree.clear();
                    break;
                }

                case 3:{
                    cout<<tree.isEmpty()<<endl;
                    break;
                }

                case 4:{
                    cout<<"Insert key: ";
                    int k;
                    cin>>k;
                    cout<<endl;
                    cout<<tree.read(k)<<endl;
                    break;
                }

                case 5:{
                    cout<<"Insert key: ";
                    int k;
                    cin>>k;
                    cout<<endl;
                    cout<<"Insert new value: ";
                    cin>>tree.read(k);
                    cout<<endl;
                    break;
                }

                case 6:{
                    cout<<"Insert key: ";
                    int k;
                    cin>>k;
                    cout<<endl;
                    cout<<"Insert new value: ";
                    int val;
                    cin>>val;
                    cout<<tree.add(val,k)<<endl;
                    break;
                }

                case 7:{
                    cout<<"Insert key: ";
                    int k;
                    cin>>k;
                    cout<<endl;
                    cout<<tree.remove(k)<<endl;
                    break;
                }

                case 8:{
                    tree.Lt_t_Rt();
                    break;
                }

                case 9:{
                    cout<<tree.ex_path_l()<<endl;
                    break;
                }

                case 10:{
                    cout<<"Tree length: "<<tree.getSize()<<endl;
                    break;
                }

                case 11:{
                    iter.first();
                    break;
                }

                case 12:{
                    iter.last();
                    break;
                }

                case 13:{
                    cout<<"Insert new value: ";
                    cin>>*iter;
                    cout<<endl;
                    break;
                }

                case 14:{
                    cout<<*iter<<endl;
                    break;
                }

                case 15:{
                    cout<<iter++<<endl;
                    break;
                }

                case 16:{
                    cout<<iter--<<endl;
                    break;
                }

                case 17:{
                    int number, min, max;
                    cout<<"Input tree length: ";
                    cin>>number;
                    cout<<endl;
                    cout<<"Input minimum value: ";
                    cin>>min;
                    cout<<endl;
                    cout<<"Input maximum value: ";
                    cin>>max;
                    cout<<endl;
                    testComplexity(number,min,max);
                    break;
                }

            }
        }catch(int code) {
            switch (code){
                case EMPTY_TREE:cout<<"Empty tree"<<endl;
                    break;
                case KEY_DOES_NOT_EXIST:cout<<"this key does not exist in tree"<<endl;
                    break;
                case ITERATOR_END:cout<<"Iterator is out of tree"<<endl;
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}