#include <cstdio>
#include <stdio.h>
#include <math.h>
 
#define pi 3.1415926535     // 円周率
int dft();

 // 離散フーリエ変換（読み込むファイル名, 書き込むファイル名）
int dft(const char filename1[], const char filename2[]){  
int k, n, i, count,N;
    int max = 10000;  // 読み込むデータ数の上限
    double f[max+1], re, im, time[max], freqency[max];
    
    //sumpuringusyuuhasuu
    double fs;
    double ts = 0.004;
    //fs = 1/ts;
    double spectrumAmplitude = 0.0;
    FILE *fp1, *fp2;
    // ファイルオープン(フーリエ変換したいデータファイル, フーリエ変換後のデータ保存用ファイル)
    if((fp1=fopen(filename1,"r"))==NULL){
        printf("FILE1 not open\n");
        return -1;
    }
    if((fp2=fopen(filename2,"w"))==NULL){
        printf("FILE2 not open\n");
        return -1;
    }
    //データの読み込み
    for(N=0; N<max; N++) {
        if(fscanf(fp1,"%lf\t%lf",&time[N] ,&f[N]) == EOF) break;
    }

    double hzTime = 0;
    for(i=0; i<max; i++) {
        if(time[i] - 0 >= 1){
            hzTime = i;
            printf("%lf\n",hzTime);
            fs = hzTime;
            break;
        }
    }
    

    printf("%lf\n",fs);
    //実数部分と虚数部分に分けてフーリエ変換
    for(n=0; n<N; n++) {
        double re = 0.0;
        double im = 0.0;
        for(k=0; k<N; k++) {
            re += f[k]*cos(2*pi*k*n/N);
            im += -f[k]*sin(2*pi*k*n/N);
            spectrumAmplitude = sqrt((re*re)+(im*im));
            //周波数:k番目の変数がどの周波数に対応するのか 
            freqency[0] = 0.0 * k;
        }
        for(count=0; count<N; count++) {
            freqency[count] = (count*fs)/N;
        }
        //fprintf(fp2,"%f, %f, %f\n", freqency[n], re, im);
        fprintf(fp2,"%f, %f, %f, %f\n", freqency[n],spectrumAmplitude, re, im);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}

int main(){
    // 離散フーリエ変換
    dft("SinWaveData.txt", "cpp.csv");
    printf("%lf",pi);
}
