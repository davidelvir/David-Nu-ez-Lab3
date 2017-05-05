#include <iostream>
using namespace std;

bool malvados(int);

int main(){
  char vivo = true;
  while(vivo){
    int opcion;
    cout<<"------Menu------"<<endl;
    cout<<"1. Numeros malvados."<<endl
        <<"2. Rotar matriz."<<endl
        <<"3. Salir"<<endl;
    cin>>opcion;
    switch(opcion){
      case 1:{
       int n;
       cout<<"Ingrese un numero: ";
       cin>> n;
       for(int i = 0; i <= n;i++){
        if(malvados(i)){
          cout<<i<<endl;
        }
       }
        break;
      }
     case 2:
        break;
     case 3:
        vivo = false;
        break;
    }
  }
}

bool malvados(int x){
  int cont = 0;
  while(x>0){
    if(x%2!=0){
      cont++;
      
    }
    x = x/2;
  }
  if(cont%2==0){
    return true;
  }
  else{
    return false;
  }
}
