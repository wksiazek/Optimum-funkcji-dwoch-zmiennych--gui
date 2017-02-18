#pragma once
#include"stdafx.h"
#include"Krzyzowanie_dwupunktowe.h"
#include"Krzyzowanie.h"
#include"Stale.h"
void Krzyzowanie_dwupunktowe::losuj_miejsca_krzyzowania(set<int>&miejsca_krzyzowan)
{
    int suma_bitow = Stale::instance()->getIlosc_bitow_x() + Stale::instance()->getIlosc_bitow_y();
    while (miejsca_krzyzowan.size() != 2)
    {
        miejsca_krzyzowan.insert(rand() % suma_bitow+1);
    }
}

void Krzyzowanie_dwupunktowe::uzyskaj_potomkow(vector<Chromosom>&populacja_rodzicow, set<int>&miejsca_krzyzowan, Chromosom &temp, Chromosom &temp2, int a, int b)
{
    //1 potomek
    temp.getGeny().insert(temp.getGeny().begin(), populacja_rodzicow[a].getGeny().begin(), populacja_rodzicow[a].getGeny().begin() + *(miejsca_krzyzowan.begin()));
    temp.getGeny().insert(temp.getGeny().end(), populacja_rodzicow[b].getGeny().begin() + *(miejsca_krzyzowan.begin()), populacja_rodzicow[b].getGeny().begin() + *(miejsca_krzyzowan.rbegin()));
    temp.getGeny().insert(temp.getGeny().end(), populacja_rodzicow[a].getGeny().begin() + *(miejsca_krzyzowan.rbegin()), populacja_rodzicow[a].getGeny().end());

    //2 potomek
    temp2.getGeny().insert(temp2.getGeny().begin(), populacja_rodzicow[b].getGeny().begin(), populacja_rodzicow[b].getGeny().begin() + *(miejsca_krzyzowan.begin()));
    temp2.getGeny().insert(temp2.getGeny().end(), populacja_rodzicow[a].getGeny().begin() + *(miejsca_krzyzowan.begin()), populacja_rodzicow[a].getGeny().begin() + *(miejsca_krzyzowan.rbegin()));
    temp2.getGeny().insert(temp2.getGeny().end(), populacja_rodzicow[b].getGeny().begin() + *(miejsca_krzyzowan.rbegin()), populacja_rodzicow[b].getGeny().end());
}