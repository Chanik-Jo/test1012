#include "test1012.h"

test1012::test1012(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	// ���������������� 
	// ������ �ٺ� 

	//connect(ui.Button1, SIGNAL(clicked()), this, SLOT(Button1()));

	QStringList tableHeader;
	tableHeader << "Menu number" << "Menu Name" << "Menu Price";
	ui.tableWidget1->setColumnCount(3); // Column�� 3���� ����
	ui.tableWidget1->setHorizontalHeaderLabels(tableHeader); // Table Header ����
	//ui.tableWidget1->insertRow(ui.tableWidget1->rowCount()); // Row�� �߰��մϴ�.
	ui.tableWidget1->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);  // �÷� ������ �ڵ� ����
	ui.tableWidget1->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);    // �÷� ������ �ڵ� ����
	for (int i = 0; i < 6; i++) {
		//ui.tableWidget_toast->insertRow(i);
		ui.tableWidget1->insertRow(ui.tableWidget1->rowCount()); // Row�� �߰��մϴ�.
		ui.tableWidget1->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
		ui.tableWidget1->setItem(i, 1, new QTableWidgetItem(QString::fromStdString("a")));
		ui.tableWidget1->setItem(i, 2, new QTableWidgetItem(QString::number(i+10)));
	}

	//QStringList tableHeader2;
	//tableHeader2 << "Menu number" << "Menu Name" << "Menu Price";
	//ui.listView1->setColumnCount(3); // Column�� 3���� ����
	//ui.listView1->setHorizontalHeaderLabels(tableHeader2); // Table Header ����
	//ui.listView1.InsertColumn(0, "menu name");
	//int nItem;

	//nItem = ui.listView1->InsertItem(0, "name");
	//ui.listView1->setItemText(0, 1, new QListView(QString::number(1)));
	//ui.listView1->Items->Add("name");
	//ui.listView1->setStringList("a");
	//int row1 = ui.listView1->currentIndex().row();

	// test : table view 
	QStandardItemModel* model = new QStandardItemModel();
	QList<QStandardItem*> items;
	items.append(new QStandardItem("AAAA"));
	items.append(new QStandardItem("BBBB"));
	items.append(new QStandardItem("CCCC"));
	items.append(new QStandardItem("DDDD"));
	items.append(new QStandardItem("EEEE"));

	model->appendRow(items);

	ui.tableView1->setModel(model);


	// test : list widget /////////////////////////////
	// db���� �޴� ����, ������ ���� �������� 
	MYSQL* conn;
	MYSQL* conn_result;
	unsigned int timeout_sec = 1;

	conn = mysql_init(NULL);
	mysql_options(conn, MYSQL_OPT_CONNECT_TIMEOUT, &timeout_sec);
	conn_result = mysql_real_connect(conn, "localhost", "root", "san", "erp", 3306, NULL, 0);

	if (NULL == conn_result) {
		std::cout << "DB Connection Fail" << endl;
	}
	else {
		std::cout << "DB Connection Success" << endl;
		// 1. select main /////////////
		MYSQL_RES* result;
		MYSQL_ROW row;
		const char* query_main = "SELECT * FROM main"; // �޴� ��ȣ, �̸�, ���� ���� ��������-> ������ ����

		if (mysql_query(conn_result, query_main)) {    // Send Query
			cout << "SELECT(main) Fail" << endl;
		}
		result = mysql_store_result(conn_result);      // Get Response
		int i = 0;
		int ii = 0;
		int iii = 0;
		while (row = mysql_fetch_row(result)) { // ��� ���ڵ� Ž�� -> �� ������ ���°� �ƴϰ� �� ��� ���� Ž����
												  // �� ��� �Ǵ��ϴ� ������ �ʿ��� 
			if (row[0]) {   // 1���� ��� �Ǵ� -> while�� �ȿ� �����Ƿ� 1������ �� ������ Ž��
				menuNumber[i] = stoi(row[0]);
				cout << "row[0] : " << row[0] << "\n";
				cout << "menuNumber : " << menuNumber[i] << "\n";
				i++;
			}
			if (row[1]) {   // 2���� ��� �Ǵ� -> while�� �ȿ� �����Ƿ� 2������ �� ������ Ž��
				menuName[ii] = row[1];
				cout << "row[1] : " << row[1] << "\n";
				cout << "menuName : " << menuName[ii] << "\n";
				ii++;
			}
			if (row[4]) {   // 5���� ��� �Ǵ� -> while�� �ȿ� �����Ƿ� 5������ �� ������ Ž��
				menuPrice[iii] = stoi(row[4]);
				cout << "row[4] : " << row[4] << "\n";
				cout << "menuPrice : " << menuPrice[iii] << "\n";
				iii++;
			}
		}
		mysql_free_result(result);       // result�� �Ҵ�� �޸𸮸� �����Ѵ�.

		// 2. select stock /////////////////////////////////
		const char* query_stock = "SELECT cquantity, tpcs, tquantity FROM stock"; // ������ �⺻ ����(����), ���, �� ���� ���� ��������-> ������ ����
		if (mysql_query(conn_result, query_stock)) { // Send Query
			cout << "SELECT(stock) Fail" << endl;
		}
		result = mysql_store_result(conn_result);    // Get Response
		int j = 0;
		int jj = 0;
		int jjj = 0;
		while (row = mysql_fetch_row(result)) { // ��� ���ڵ� Ž��
			if (row[0]) {                           // 1���� ��� �Ǵ�
				resourceCquantity[j] = stoi(row[0]);
				cout << "row[0] : " << row[0];
				cout << "resourceCquantity : " << resourceCquantity[j] << "\n";
				j++;
			}
			if (row[1]) {                           // 2���� ��� �Ǵ�  
				resourceTpcs[jj] = stoi(row[1]);
				cout << "row[1] : " << row[1];
				cout << "resourceTpcs : " << resourceTpcs[jj] << "\n";
				jj++;
			}
			if (row[2]) {                          // 3���� ��� �Ǵ�
				resourceTquantity[jjj] = stoi(row[2]);
				cout << "row[2] : " << row[2];
				cout << "resourceTquantity : " << resourceTquantity[jjj] << "\n";
				jjj++;
			}
		}
		mysql_free_result(result);       // result�� �Ҵ�� �޸𸮸� �����Ѵ�.
		mysql_close(conn);
	}
	//return;

	for (int i = 0; i < 6; i++) {
		ui.listWidget1->addItem(QString::number(i+1) + "\t" + QString::fromStdString("aa"));
	}
	  // "aa" : error ....;;;;SS

}
//void test1012::Button1() {
//	name[0] = "zazeungnaa";
//	price[0] = 50000;
//	quantity[0] = 2;
//	resource[0] = 30;
//	//string p = price[0].toStdString();
//	string p[10] = {};
//	p[0] = "a";
//	cout << p[0];
//	string q[10];
//	string pq[10];
//	string r[10];
//	p[0]= to_string(price[0]);
//	q[0] = to_string(quantity[0]);
//	pq[0] = to_string(price[0]*quantity[0]);
//	r[0] = to_string(resource[0]);

	/*int p[10];
	p[0] += 1;
	cout << p[0];
	cout << price[0] + 1;*/


	///db ����       /////// menu name, menu price ������ ���� 
	//MYSQL conn;
	//MYSQL* conn_result;
	//int query_state;      // �ֿֿֿֿֿֿֿֿ� string���� �����ϸ� �ȵǳİ�....��
	//unsigned int timeout_sec = 1;

	//mysql_init(&conn);
	////mysql_options(&conn, MYSQL_OPT_CONNECT_TIMEOUT, &timeout_sec);
	//conn_result = mysql_real_connect(&conn, "192.168.0.25", "root", "1234", "erp", 3306, NULL, 0);

	//if (NULL == conn_result) {
	//	cout << "DB Connection Fail" << endl;
	//}
	//else {
	//	cout << "DB Connection Success" << endl;


	//	// 1. insert sales /////////////
	//	//const char* query_main = "insert into main (prizename, regdate, price) values(name[0].toStdString(), currentDate().toStdString(), stoi(price[0]))";    // �޴� �̸�, ���� ���� �ҷ�����-> ������ ����
	//	string query_sales = "insert into sales (prizename, price, pcs, agg, saldate, saltime) values('"+name[0]+"', '" + p[0] + "', '" + q[0] + "', '" + pq[0] + "', '"+currentDate()+"', '" + currenttime() + "')";
	//	//string queryz = "UPDATE stock SET tpcs= '" + stgro + "',tquantity='" + tity + "'  where ingre = '" + stgrew + "' ";
	//	//const char* query2 = query_sales.c_str();
	//	query_state = mysql_query(conn_result, query_sales.c_str());
	//	if (query_state) // ���� �� -1
	//	{
	//		cout << "Query Error : " << mysql_error(&conn) << endl;
	//		cout << "Query_state : " << mysql_query(conn_result, query_sales.c_str()) << endl;
	//		return; // ������ ���� �� ����ó��(�Լ� ����)
	//	}
	//	// Send Query
	//	/*if (mysql_query(conn_result, query_sales.c_str())) {
	//		cout << "insert(sales) Fail" << endl;
	//	}*/
	//	mysql_close(&conn);
	//}
	//return;

	//QMessageBox MsgBox;
	///*QComboBox* combo1 = new QComboBox();
	//QLineEdit* lineEdit1 = new QLineEdit();*/
	//QComboBox combo1;
	//QLineEdit lineEdit1;

	//MsgBox.setWindowTitle("Modify the price");
	//MsgBox.setText("Please select the menu and\ninput the revised price.");
	//MsgBox.layout()->addWidget(combo1);
	//MsgBox.layout()->addWidget(lineEdit1);
	////lineEdit1->setText(0);    // lineEdit�� �⺻ ��°� 0
	//MsgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
	//MsgBox.setDefaultButton(QMessageBox::Yes);
	//for (int j = 0; j < 10; j++) {
	//	combo1->addItem(QString::fromStdString(name[j]));
	//}
	////cc = QString::number(combo1->currentIndex());
	////cc = combo1->currentIndex().toInt();    // combobax�� string
	////string cc = combo1->currentIndex();
	//int cc = combo1->currentIndex();
	//cout << "cc : " << cc << "\n";
	////qDebug() << "cc : " << cc.toStdString;
	///*int ccc = cc.toInt();*/
	////int ccc = stoi(cc);
	////int ccc = cc.toStdInt();
	////cout << "ccc : " << ccc << "\n";
	////qDebug() << "ccc : " << ccc;

//}