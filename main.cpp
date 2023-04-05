#include <iostream>
#include <cstring>
using namespace std;

struct APARAT{
    char nume[51];
    char categorie[51];
    char camera[51];
    int consum;
}aparate[101];

bool isNotInLista(char lista[51][51], char categorie[], int a){
    for(int i = 0; i < a; i++){
        if(strcmp(lista[i], categorie) == 0)
            return false;
    }
    return true;
}

int afiseazaNrCategorii(int n){
    int a = 0;
    char lista[51][51];
    for(int i = 0; i < n; i++){
        if(isNotInLista(lista, aparate[i].categorie, a)){
            strcpy(lista[a++], aparate[i].categorie);
        }
    }

    return a;
}

void calculeazaItemeCamera(int i, char listaCamere[51][51], int numarItemeCamera[], int a){
    for(int j = 0; j < a; j++){
        if(strcmp(listaCamere[j], listaCamere[i]) == 0){
            numarItemeCamera[i]++;
        }
    }
}

void afiseazaBestRoom(int n){
    int a = 0;
    char listaCamere[51][51];
    int numarItemeCamera[51] = {0};

    for(int i = 0; i < n; i++){
        if(isNotInLista(listaCamere, aparate[i].camera, a)){
            strcpy(listaCamere[a++], aparate[i].camera);
        }
    }

    for(int i = 0; i < a; i++){
        calculeazaItemeCamera(i, listaCamere, numarItemeCamera, a);
    }

    int maxim = -1, pozMaxim;
    for(int i = 0; i < a; i++){
        if(numarItemeCamera[i] > maxim){
            maxim = numarItemeCamera[i];
            pozMaxim = i;
        }
        else if(numarItemeCamera[i] == maxim){
            if(strcmp(listaCamere[pozMaxim], listaCamere[i]) > 0){
                pozMaxim = i;
            }
        }
    }
    cout<<listaCamere[pozMaxim]<<endl;
}

void sorteazaConsum(int n){
    int i,j;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(aparate[i].consum > aparate[j].consum){
                swap(aparate[i], aparate[j]);
            }
            else if(aparate[i].consum == aparate[j].consum){
                if(strcmp(aparate[i].nume, aparate[j].nume) > 0){
                    swap(aparate[i], aparate[j]);
                }
            }
        }
    }
    for(i = 0; i <n; i++){
        cout<<aparate[i].nume<<endl;
    }
}

int calculeazaConsumAparat(char numeAparat[], int numarOre, int n){
    for(int i = 0; i < n; i++){
        if(strcmp(aparate[i].nume, numeAparat) == 0){
            return numarOre * aparate[i].consum;
        }
    }
    return 0;
}

void calculeazaConsumTotal(int n){
    char numeAparat[51];
    int numarOre, consumTotal = 0;
    while(cin>>numeAparat){
        cin>>numarOre;
        consumTotal += calculeazaConsumAparat(numeAparat, numarOre, n);
    }

    cout<<consumTotal<<endl;
}

void calculeazaConsumMaxim(int n){

    int a = 0;

    char listaAparate[51][51];
    int oreFunctionate[51] = {0};
    int consumAparat[51] = {0};

    char aparatCurent[51];
    int oreFuntionateAparatCurent;

    while(cin>>aparatCurent){
        cin>>oreFuntionateAparatCurent;

        if(isNotInLista(listaAparate, aparatCurent, a)){
            strcpy(listaAparate[a], aparatCurent);
            oreFunctionate[a] += oreFuntionateAparatCurent;
            a++;
        }
    }

    for(int i = 0; i < a; i++){
        consumAparat[i] = calculeazaConsumAparat(listaAparate[i], oreFunctionate[i], n);
    }

    int maxim = -1, pozMaxim;
    for(int i = 0; i <a; i++){
        if(maxim < consumAparat[i]){
            maxim = consumAparat[i];
            pozMaxim = i;
        }
    }

    cout<<listaAparate[pozMaxim]<<' '<<maxim<<endl;
}

int main()
{
    int n;
    char opt[21];

    cin>>n;

    for(int i=0; i < n; i++){
        cin>>aparate[i].nume;
        cin>>aparate[i].categorie;
        cin>>aparate[i].camera;
        cin>>aparate[i].consum;
    }

    cin>>opt;

    if(strcmp(opt, "nr_categorii") == 0){
        cout << afiseazaNrCategorii(n) << endl;
    }
    else if(strcmp(opt, "best_room") == 0){
        afiseazaBestRoom(n);
    }
    else if(strcmp(opt, "sort_consum") == 0){
        sorteazaConsum(n);
    }
    else if(strcmp(opt, "consum_total_timp") == 0){
        calculeazaConsumTotal(n);
    }
    else if(strcmp(opt, "consum_max_timp") == 0){
        calculeazaConsumMaxim(n);
    }
}
Footer
© 2023 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
