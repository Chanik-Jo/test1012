#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test1012.h"
#include <mysql.h>
#include <iostream>
#include <ctime>
#include <string>
#include <QMessageBox> 
#include <QComboBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QListView>
#include <QStringList>
#include <QTableView>
#include <QStandardItemModel>
#include <QListWidget>


using namespace std;

class test1012 : public QMainWindow
{
    Q_OBJECT

public:
    test1012(QWidget *parent = Q_NULLPTR);

//    string name[10] = {};     // �̷��� ���ϰ� string name[10];  �̰͸� �ϸ�....+= ������ ������ ���� �� ���ٿ�...���Ͱ� �ƴ϶��...��
//    int price[10] = {};
//    int quantity[10] = {};
//    //int p_q[10];
//    int resource[17] = {};
//
//    // ���� ��¥, ���� �ð�
//    string currentDate() {
//        time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
//        struct tm  tstruct;
//        char       buf[30];
//        tstruct = *localtime(&now);
//        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct); // YYYY-MM-DD ������ ��Ʈ��
//
//        return buf;
//    }
//    string currenttime() {
//        time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
//        struct tm  tstruct;
//        char       buf[30];
//        tstruct = *localtime(&now);
//        strftime(buf, sizeof(buf), "%X", &tstruct); // HH:mm:ss ������ ��Ʈ��
//
//        return buf;
//    }
    int menuNumber[100] = {};     // menu number <- selecting in db
    string menuName[100] = {};    // menu name  <- selecting in db
    int menuPrice[100] = {};      // menu price <- selecting in db
    //string menu_p[100] = {};      // menu price  -> inserting in db
    string order_na[100] = {};    // order menu name -> inserting in db
    int orderPrice[100] = {};     // order menu price
    string order_p[100] = {};     // order menu price -> inserting in db
    int orderQuantity[100] = {};  // order menu quantity
    string order_q[100] = {};     // order menu quantity -> inserting in db

    int orderNumber[100] = {};    // order number <- selecting in db
    string order_num[100] = {};   // order number -> inserting in db  

    int menuSumprice[100] = {};   // ui ��¿� �ֹ� �޴� �ܰ� * ���� 
    int menuPayment[100] = {};    // ui ��¿� �ֹ� �Ѿ� 

    string currentDate() {  // ���� ��¥
        time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
        struct tm  tstruct;
        char       buf[30];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct); // YYYY-MM-DD ������ ��Ʈ��

        return buf;
    }
    string currenttime() {  //���� �ð�
        time_t     now = time(0); //���� �ð��� time_t Ÿ������ ����
        struct tm  tstruct;
        char       buf[30];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%X", &tstruct); // HH:mm:ss ������ ��Ʈ��

        return buf;
    }
    int resourceCquantity[17] = {};  // food resource cquantity <- selecting in db
    int resourceTpcs[17] = {};       // food resource tpcs <- selecting in db
    int resourceTquantity[17] = {};  // food resource tquantity <-selecting in db

    int orderTquantity[17] = {};     // order resource tquantity : calculation
    int calculateTquantity[17] = {}; // tquantity = resourceTquantity[i] - orderTquantity[i] 
    string calculate_tq[17] = {};    // tquantity -> updating in db
    int calculateTpcs[17] = {};      // tpcs= (resourceTquantity[i]-orderTquantity[i])/resourceCquantity[i]
    string calculate_tp[17] = {};    // tpcs <- updating in db

//private slots:
//    void Button1();

private:
    Ui::test1012Class ui;
};
