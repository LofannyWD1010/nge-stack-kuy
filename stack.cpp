/*Muhammad Rifki Setiawan - 1717051004
  Muhammad Rama Wicaksono - 1717051062
  Yosua Sandi Susanto     - 1717051064
  Lofanny Wahyu Dandi     - 1757051010
  */

  //link : https://github.com/LofannyWD1010/nge-stack-kuy

#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

bool Operator(char opr){
    if(opr == '+'||opr == '-'||opr == '*'||opr == '/') return true;
    else return false;
}

bool Operand(char opr){
    if(opr>='0' && opr<='9') return true;
    else return false;
}

int compare(char opr1, char opr2){
    if((opr1 == '*'||opr1=='/')&&(opr2=='+'||opr2=='-')) return -1;
    else if((opr1=='+'||opr1=='-')&&(opr2=='*'||opr2=='/')) return 1;
    else return 0;
}

int main(){
    stack<char> S;
    string P = "";
    char input[50];
    cin>>input;
    char *ptr=input;

    while(*ptr != '\0'){
        if(Operand(*ptr))
            P += *ptr;
        else if(*ptr=='(')
            S.push(*ptr);
        else if(*ptr==')'){
            while(!S.empty()&& S.top()!='('){
                P += S.top();
                S.pop();
            }
            S.pop();
        }
        else if(Operator(*ptr)){
           while(!S.empty()&& S.top()!='(' && compare(S.top(),*ptr)<=0){
                P += S.top();
                S.pop();
            }
            S.push(*ptr);
        }
    ptr++;
    }
    while(!S.empty()){
        P += S.top();
        S.pop();
    }
    cout<<P<<endl;

    //postfix
    //char *pnilai = P;
    //int A, B;

    //while(*pnilai != '\0'){
    //    if(Operand(*pnilai)) S.push(*pnilai);
    //    else if(Operator(*pnilai)){
    //            S.top()==A;
    //            S.pop();
    //            S.top()==B;
    //            S.pop();
    //}
    //}
    return 0;
}
