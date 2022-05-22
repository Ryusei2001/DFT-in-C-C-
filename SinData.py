#! /usr/bin/env python
# -*- coding: utf-8 -*-
# pythonモジュールの読込 
import sys
import numpy as np
import matplotlib.pyplot as plt
# プログラムのメイン関数 
def main():
    # コマンドライン引数の処理
    argvs = sys.argv # コマンドライン引数を格納したリストの取得 
    argc = len(argvs) # 引数の個数
    if (argc != 2):
        print('Usage: python SinData.py OutFile(**.txt)') 
        quit()
    # 出力ファイルを開く
    # argvs[0]:プログラム名であるSinData.pyが格納されている # argvs[1]:出力ファイル名が格納されている
    fout = open(argvs[1], 'w')
    # 解析対象の関数 ### パラメータ 
    freq = 10.0
    amp = 2.0
    phase = np.pi/3.0 
    ts = 0.004
    fs = 1.0 / ts
    t1 = 0.0
    t2 = 10.0
    # 周波数 [Hz]
    # 振幅
    # 位相
    # サンプリング周期(秒) -> サンプリング周波数は250Hz # サンプリング周期(Hz)
    # 観測時間 [t1, t2] (秒)
    ### 関数
    t = np.arange(t1, t2, ts)
    #x = amp * np.cos(2.0*np.pi*freq*t + phase)
    x = (2*np.cos(2.0*np.pi*2*t+np.pi/3))+(1*np.cos(2.0*np.pi*10*t+np.pi/2))+(0.5*np.cos(2.0*np.pi*40*t-np.pi/6))
    # 関数を出力ファイルに書き込む 
    for i in range(0, len(t)):
        # 書式は「時間(t) 振幅(x)」
        # 時間と振幅の間は’¥t’でタブ区切り、振幅の次は’¥n’で改行 
        data = str(t[i]) + '\t' + str(x[i]) + '\n'
        fout.write(data)
    # グラフ表示 
    plt.plot(t,x) 
    plt.show()
    # 最初に実行されるモジュール
    # このif文がtrueであれば、上のdefで定義されたmain()が実行される 

if __name__ == "__main__":
    main()