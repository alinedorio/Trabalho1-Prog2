#include "../headers/tData.h"
//struct que apresenta tudo que é necessário para se obter uma data.
struct tdata{
    int dia;
    int mes;
    int ano;
};
//função que cria uma data.
tData* criarData(int dia, int mes, int ano) {
  tData* data = (tData*) malloc(sizeof(struct tdata));
  data->dia = dia;
  data->mes = mes;
  data->ano = ano;
  return data;
}

tData* filtroDeData(char* data) {
  int dia, mes, ano;
  sscanf(data, "%d/%d/%d", &mes, &dia, &ano);
  return criarData(dia,mes,ano);
}
//funções que retornam apenas uma determinada parte da data, ao receber ela inteira por meio da struct tData.
int getDia(tData* data) {return data->dia;}
int getMes(tData* data) {return data->mes;}
int getAno(tData* data) {return data->ano;}

//função para conferir se o ano é bissexto. Será usada na função tempoEntreDatas.
int bissexto (int ano) {
  int anobi = 0;
  if (ano%400==0){
      anobi = 1;
      }
      else {
          if (ano%100==0){
              anobi = 0;
          }
          else {
              if (ano%4==0){
                  anobi = 1;
              }
              else {
                  anobi = 0;
              }
          }
      }
  return (anobi);
}

//funcao que confere quantos dias tem no mes.
int conferirmes(int mes, int ano){
  
  int diamax, anobi = bissexto(ano);
    if (mes==1 || mes==3 || mes==5 || mes==7 || mes== 8 || mes==10 || mes==12 ){
        diamax=31;
    }
    else if (mes==2){
        if (!anobi){
            diamax=28;
        }
        else{
            diamax=29;
        }
    }
    else {
        diamax=30;
    }
return (diamax);
}

//função para calcular quantos dias tem no intervalo entre duas datas.
int tempoEntreDatas(tData* data1, tData* data2) {
  int tempo;
  if (data1->ano == data2->ano) {
    tempo = diaDoAno(data2) - diaDoAno(data1);
  } else {
    tempo = 365*(data2->ano - data1->ano);
    tempo += diaDoAno(data2) - diaDoAno(data1);
  }
  return tempo;
}
//função que deleta uma data.
void deletarData(tData* data) {
  free(data);
  data = NULL;
}


int diaDoAno(tData* data) {
  int i = 1;
  int mes = data->mes;
  int diaDoAno = data->dia;
  while (mes != i) {
    diaDoAno+=conferirmes((mes-i), data->ano);
    i++;
  }
  return diaDoAno;
}

tData* getData(int diaDoAno, int ano) {
  int dia = 0;
  int mes = 1;
  if (diaDoAno <= 31) {
    dia = diaDoAno;
  } else if (diaDoAno <= (59 + bissexto(ano)) ) {
    dia = diaDoAno - 31;
    mes = 2;
  } else if (diaDoAno <= (90 + bissexto(ano)) ) {
    dia = diaDoAno - (59 + bissexto(ano));
    mes = 3;
  }else if (diaDoAno <= (120 + bissexto(ano)) ) {
    dia = diaDoAno - (90 + bissexto(ano));
    mes = 4;
  }else if (diaDoAno <= (151 + bissexto(ano)) ) {
    dia = diaDoAno - (120 + bissexto(ano));
    mes = 5;
  }else if (diaDoAno <= (181 + bissexto(ano)) ) {
    dia = diaDoAno - (151 + bissexto(ano));
    mes = 6;
  }else if (diaDoAno <= (212 + bissexto(ano)) ) {
    dia = diaDoAno - (181 + bissexto(ano));
    mes = 7;
  }else if (diaDoAno <= (243 + bissexto(ano)) ) {
    dia = diaDoAno - (212 + bissexto(ano));
    mes = 8;
  }else if (diaDoAno <= (273+ bissexto(ano)) ) {
    dia = diaDoAno - (243 + bissexto(ano));
    mes = 9;
  }else if (diaDoAno <= (304 + bissexto(ano)) ) {
    dia = diaDoAno - (273 + bissexto(ano));
    mes = 10;
  }else if (diaDoAno <= (334 + bissexto(ano)) ) {
    dia = diaDoAno - (304 + bissexto(ano));
    mes = 11;
  }else if (diaDoAno <= (365 + bissexto(ano)) ) {
    dia = diaDoAno - (334 + bissexto(ano));
    mes = 12;
  } else{
    diaDoAno -= 365+bissexto(ano);
    ano+=1;
    return getData(diaDoAno, ano);
  }
  return criarData(dia, mes, ano);
}
