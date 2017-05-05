#include <iostream>
#include <string>

using namespace std;

bool malvados(int);
int** rotar(int**,int);
void imprimir(int,int**,int,int);
int** crear(int);
void liberar(int,int**);
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
       while(n<0){
        cout<<"El numero no puede ser negativo. Ingrese otro valor: ";
        cin>>n;
       }
       cout<<"Los numeros malvados hasta "<<n<<" son: "<<endl;
       for(int i = 0; i <= n;i++){
        if(malvados(i)){
          if(i==0){
            cout<<0<<" "<<0<<endl;
          }else{
            
            cout<<"  "<<i<<endl;
          }
        }
        //cout<<endl;
       }
       //cout<<endl;
        break;
      }
     case 2:{
        int** matriz;
      
        matriz = crear(5);
        cout<<"Matriz original: "<<endl;
        imprimir(5,matriz,0,0);
        
        cout<<"Matriz rotada: "<<endl;
        matriz = rotar(matriz,5);
        imprimir(5,matriz,0,0);
        liberar(5,matriz); 
        break;
      }
     case 3:
        vivo = false;
        break;
    }
  }
}

bool malvados(int x){
  int cont = 0;
  string bin = "";
  while(x>0){
    if(x%2!=0){
      cont++;
      bin = "1" + bin;
    }else{
      bin = "0" + bin;
    }
    x = x/2;
  }
 
  if(cont%2==0){
    cout<<bin;
    return true;
  }
  else{
    return false;
  }
}
void imprimir(int n,int** matriz,int i,int j){
  if(i<n){
    if(j <n){
      cout<<matriz[i][j]<<" ";
      imprimir(n,matriz,i,j+1);
    }else{
      cout<<endl;
      imprimir(n,matriz,i+1,0);
    }
  }

}
int** rotar(int** matriz,int n){
  int** retorno = crear(5);
  int tem = 4;
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      retorno[j][tem] = matriz[i][j];
    }
    tem--;
  }
  return retorno;
}
int** crear(int n){
  int** ret = new int*[n];
  for(int i=0;i<n;i++){
    ret[i]=new int[n];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ret[i][j] = i+j;
    }
  }
  return ret;
}
void liberar(int n, int** matriz){
  for(int i = 0;i<n;i++){
    delete[]matriz[i];
  }
  delete[]matriz;
}
