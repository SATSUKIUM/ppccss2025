#include <TStyle.h>
#include <TCanvas.h>

#include <TSystem.h>

// C++の標準ライブラリ
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

// 時刻情報
#include <iomanip>
#include <chrono>
#include <ctime>

// ヒストグラム関係
#include <TH1.h>
#include <TH2.h>

// グラフ
#include <TGraphErrors.h>
#include <TLegend.h>

// 見栄え関係
#include <TPad.h>
#include <TColor.h>

void drawHistogram()
{
  TH1F* myHist = new TH1F("myHist", "My first histogram", 10, 0., 10.);
  myHist->Fill(3.4);
  myHist->Fill(3.4);
 
  myHist->SetFillStyle(3004);
  myHist->SetFillColor(2);
  myHist->Draw();
}