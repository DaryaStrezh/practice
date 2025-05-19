#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct atc {
	int date[3] = { 0,0,0 };	// дата разговора {число.месяц.год}			
	int code = 0;				// код города								
	string city;				// название города							
	int time[3] = { 0,0,0 };	// время разговора {часы.минуты.секунды}	
	double tarif = 0;			// тариф									
	string city_num;			// номер телефона в городе					
	string subscriber_num;		// номер телефона абонента
};

struct memory {
	int code = 0;
	string city;
	int time = 0;
	double tarif = 0;
	double sum = 0;
	int time_all[3] = { 0,0,0 };
};

// Определение функций
void QuickSort(atc contact[], int left, int right);					// Быстрая сортировка (по коду города)
void DirectSelectionSorting(atc contact[], int n);					// Сортировка методом прямого выбора (по коду города)
void LinearSearch(atc contact[], int N, memory task[], int count);	// Линейный поиск (по коду города)
void OutputTableHead();												// Вывод шапки таблицы
void OutputTableBody(atc contact[], int N);							// Вывод тела таблицы
void MakeFile(string file_name);									// Создать файл
void EditFile(string file_name);									// Редактировать файл
void SortAndSearch(string file_name, int kod);						// Сортировка и линейный поиск


// Быстрая сортировка (по коду города)
void QuickSort(atc contact[], int left, int right) {
	if (left > right) return;
	atc c = contact[(left + right) / 2];
	int i = left;
	int j = right;
	atc temp;
	while (i <= j) {
		while (contact[i].code < c.code) i++;
		while (contact[j].code > c.code)j--;
		if (i <= j) {
			temp = contact[i];
			contact[i] = contact[j];
			contact[j] = temp;
			i++;
			j--;
		}
	}
	QuickSort(contact, left, j);
	QuickSort(contact, i, right);
}


// Сортировка методом прямого выбора (по коду города)
void DirectSelectionSorting(atc contact[], int n) {
	int m = 0;
	atc r = contact[0];
	for (int i = 0; i <= n; i++) {
		m = i;
		for (int j = i + 1; j <= n; j++) {
			if (contact[j].code <= contact[m].code) m = j;
			
		}
		r = contact[m];
		contact[m] = contact[i];
		contact[i] = r;
	}
}


// Линейный поиск (по коду города)
void LinearSearch(atc contact[], int N, memory task[], int count) {
	int j = 0;
	for (int i = 1; i < N; i++) {
		if (contact[i].code == contact[i - 1].code) {
			task[j].time += contact[i].time[0] * 3600 + contact[i].time[1] * 60 + contact[i].time[2];
			task[j].code = contact[i].code;
			task[j].city = contact[i].city;
			task[j].tarif = contact[i].tarif;
			task[j].sum += task[j].tarif * task[j].time;

			task[j].time_all[0] = task[j].time / 3600;
			task[j].time_all[1] = task[j].time % 3600;
			task[j].time_all[2] = task[j].time_all[1] % 60;
			task[j].time_all[1] = task[j].time_all[1] / 60;
		}
		else {
			j++;
			task[j].time += contact[i].time[0] * 3600 + contact[i].time[1] * 60 + contact[i].time[2];
			task[j].code = contact[i].code;
			task[j].city = contact[i].city;
			task[j].tarif = contact[i].tarif;
			task[j].sum += task[j].tarif * task[j].time;

			task[j].time_all[0] = task[j].time / 3600;
			task[j].time_all[1] = task[j].time % 3600;
			task[j].time_all[2] = task[j].time_all[1] % 60;
			task[j].time_all[1] = task[j].time_all[1] / 60;
		}
	}
}

// Вывод шапки таблицы
void OutputTableHead() {
	cout << setw(5) << left << "  #"
		<< setw(16) << left << "Дата разговора" << "|"
		<< setw(6) << "  Код" << "|"
		<< setw(10) << "  Город" << "|"
		<< setw(17) << " Время разговора" << "|"
		<< setw(9) << "  Тариф" << "|"
		<< setw(14) << " Исходящий" << "|"
		<< setw(16) << " Входящий" << "|"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
}


// Вывод тела таблицы
void OutputTableBody(atc contact[], int N) {
	for (int i = 0; i < N; i++) {
		cout << setw(3) << right << i + 1 << ".";

		if (contact[i].date[0] < 10)cout << right << setw(8) << "0" << contact[i].date[0] << ".";
		else cout << right << setw(9) << contact[i].date[0] << ".";
		if (contact[i].date[1] < 10) cout << "0" << contact[i].date[1] << ".";
		else cout << contact[i].date[1] << ".";
		cout
			<< contact[i].date[2] << "|"
			<< setw(6) << contact[i].code << "|"
			<< setw(10) << contact[i].city << "|";
		if (contact[i].time[0] < 10) cout << setw(10) << "0" << contact[i].time[0] << ".";
		else cout << setw(11) << contact[i].time[0] << ".";
		if (contact[i].time[1] < 10) cout << "0" << contact[i].time[1] << ".";
		else cout << contact[i].time[1] << ".";
		if (contact[i].time[2] < 10) cout << "0" << contact[i].time[2] << " ";
		else cout << contact[i].time[2] << "|";
		cout
			<< setw(9) << contact[i].tarif << "|"
			<< setw(14) << contact[i].city_num << "|"
			<< setw(16) << contact[i].subscriber_num << "|"
			<< endl;
	}
}


// Создать файл
void MakeFile(string file_name) {
	ofstream file;
	file.open(file_name);
	if (!file.is_open()) {
		cout << "Ошибка. Файл не был открыт!" << endl;
	}
	else {
		cout << "Файл с именем "<< file_name <<" был создан." << endl;
		file.close();
	}
}


// Редактировать файл
void EditFile(string file_name) {
	bool flag = true;
	while (flag) {
		int temp_answ = 0;
		int answer = 0;
		string temp_string;
		cout << "\nРабота с файлом: " << file_name
			<< ":\n1. просмотр файла\n2. Добавить запись в файл\n3. Изменить запись в файле\n4. Удалить запись из файла\n5. Задание\n\n0. Выход в главное меню\n\n";
		cin >> answer;

		if (answer == 0) { // 0 - выход в главное меню
			flag =false;
		}
		if (answer == 2) { // 2 - добавить запись в файл
			int answer1 = 1;

			int oN = 0;
			ifstream file;
			file.open(file_name);
			if (!file.is_open()) cout << "Ошибка. Файл не был открыт!" << endl;

			else {
				file.seekg(0);
				string f_str;
				getline(file, f_str);
				if (f_str == "") oN = 0;
				else oN = 1;
				file.close();

				ofstream file;                                                 // поток записи в файл
				file.open(file_name, ios::app);                                // открыть файл в режиме app, чтобы указатель переместился в конец файла и предыдущие данные не стерлись
				if (!file.is_open()) {
					cout << "Ошибка. Файл не был открыт!" << endl;
				}
				else {
					string t_date, t_code, t_city, t_time, t_city_num, t_subscriber_num;
					double t_tarif;
					answer1 = 1;
					while (answer1 == 1) {
						cout << "Дата разговора (в формате ДД.ММ.ГГ 13.04.2025): " << endl;
						cin >> t_date;
						cout << "Код города: " << endl;
						cin >> t_code;
						cout << "Город: " << endl;
						cin >> t_city;
						cout << "Продолжительность разговора (в формате ЧАСЫ.МИНУТЫ.СЕКУНДЫ): " << endl;
						cin >> t_time;
						cout << "Тариф: " << endl;
						cin >> t_tarif;
						cout << "Номер города: " << endl;
						cin >> t_city_num;
						cout << "Номер абонента: " << endl;
						cin >> t_subscriber_num;
						cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
						cin >> temp_answ;

						if (temp_answ == 1) {
							if (oN != 0)  file << "\n";
							else oN = 1;
							file << t_date << " " << t_code << " " << t_city << " " << t_time << " " << t_tarif << " " << t_city_num << " " << t_subscriber_num;
						}
						else cout << "Данные не были добавлены в файл!" << endl;
						cout << "Желаете добавить еще запись? \n1 - да\n2 - нет" << endl;
						cin >> answer1;
					}
					file.close();
				}
			}
		}


		//	1 - просмотр файла+					3 - изменить запись в файле
		//	4 - удалить запись из файла			5 - выполнение задания

		if (answer == 1 || answer == 3 || answer == 4 || answer == 5) {

			int N = 0;
			ifstream file;
			file.open(file_name);
			if (!file.is_open()) cout << "Ошибка. Файл не был открыт!" << endl;

			else {
				file.seekg(0);
				int oN = 0;
				string f_str;
				getline(file, f_str);
				if (f_str == "") cout << "Файл пуст!" << endl;
				else {
					file.seekg(0);
					while (!file.eof()) {					//	считаем количество строк в файле
						getline(file, temp_string, '\n');
						oN++;
					}
					N = oN;
					oN = 0;
					file.seekg(0);
					atc* contact = new atc[N]; // массив структур 
					int i = 0;
					string temp_d, temp_t;
					while (!file.eof() && i <= N - 1) { // вытягиваем данные с файла в массив структур
						file >> temp_d >> contact[i].code >> contact[i].city >> temp_t >> contact[i].tarif >> contact[i].city_num >> contact[i].subscriber_num;
						contact[i].date[0] = stoi(temp_d.substr(0, 2));
						contact[i].date[1] = stoi(temp_d.substr(3, 2));
						contact[i].date[2] = stoi(temp_d.substr(6, 4));

						contact[i].time[0] = stoi(temp_t.substr(0, 2));
						contact[i].time[1] = stoi(temp_t.substr(3, 2));
						contact[i].time[2] = stoi(temp_t.substr(6, 2));
						i++;
					}
					file.close();
					i = 0;
					if (answer == 1) {				// 1 - просмотр файла
						OutputTableHead();
						OutputTableBody(contact, N);
					}

					if (answer == 3) {
						cout << "Исходный список: " << endl;
						OutputTableHead();
						OutputTableBody(contact, N);
						int index_number = 0, answer3 = 0;
						string temp_date, temp_time;
						cout << "\nВведите порядковый номер записи, которую желаете изменить: ";
						cin >> index_number;
						index_number--;
						if (index_number <= N) {
							cout << "\nЧто вы желаете изменить? \n1 - дата разговора \n2 - код города \n3 - название города \n4 - время разговора \n5 - тариф \n6 - номер телефона города \n7 - номер телефона абонента" << endl;
							cin >> answer3;
							switch (answer3) {
							case 1:
								cout << "Введите дату разговора в формате ДД.ММ.ГГ:" << endl;
								cin >> temp_date;
								break;
							case 2:
								cout << "Введите индекс города:" << endl;
								cin >> contact[index_number].code;
								break;
							case 3:
								cout << "Введите название города:" << endl;
								cin >> contact[index_number].city;
								break;
							case 4:
								cout << "Время разговора (ЧЧ.ММ.СС):" << endl;
								cin >> temp_time;
								break;
							case 5:
								cout << "Введите тариф:" << endl;
								cin >> contact[index_number].tarif;
								break;
							case 6:
								cout << "Введите номер телефона города: " << endl;
								cin >> contact[index_number].city_num;
								break;
							case 7:
								cout << "Введите номер телефона абонента:" << endl;
								cin >> contact[index_number].subscriber_num;
								break;
							default:
								cout << "Неверный ответ. Попробуйте еще раз.\n";
							}

							cout << "Измененная запись: " << endl;
							if (answer3 == 1) { //date
								cout
									<< temp_date << " " << contact[index_number].code << " "
									<< contact[index_number].city << " "
									<< contact[index_number].time[0] << "."
									<< contact[index_number].time[1] << "."
									<< contact[index_number].time[2] << " "
									<< contact[index_number].tarif << " " << contact[index_number].city_num << " " << contact[index_number].subscriber_num << endl;
							}
							else if (answer3 == 4) {//time
								cout
									<< contact[index_number].date[0] << "."
									<< contact[index_number].date[1] << "."
									<< contact[index_number].date[2] << " "
									<< " " << contact[index_number].code << " " << contact[index_number].city
									<< " " << temp_time << " " << contact[index_number].tarif << " "
									<< contact[index_number].city_num << " " << contact[index_number].subscriber_num << endl;
							}
							else {
								cout
									<< contact[index_number].date[0] << "."
									<< contact[index_number].date[1] << "."
									<< contact[index_number].date[2] << " "
									<< contact[index_number].code << " " << contact[index_number].city << " "
									<< contact[index_number].time[0] << "."
									<< contact[index_number].time[1] << "."
									<< contact[index_number].time[2] << " "
									<< contact[index_number].tarif << " " << contact[index_number].city_num
									<< " " << contact[index_number].subscriber_num << endl;
							}
							cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
							cin >> temp_answ;

							if (temp_answ == 1) {
								ofstream file;
								file.open(file_name);
								for (int i = 0; i < N; i++) {
									if (i == index_number && answer3 == 1) {
										file << temp_date << " "
											<< contact[i].code << " " << contact[i].city << " ";
										if (contact[i].time[0] < 10) file << "0" << contact[i].time[0] << ".";
										else file << contact[i].time[0] << ".";
										if (contact[i].time[1] < 10) file << "0" << contact[i].time[1] << ".";
										else file << contact[i].time[1] << ".";
										if (contact[i].time[2] < 10) file << "0" << contact[i].time[2] << " ";
										else file << contact[i].time[2] << " ";

										file << contact[i].tarif << " " << contact[i].city_num << " " << contact[i].subscriber_num;
									}

									else if (i == index_number && answer3 == 4) {
										if (contact[i].date[0] < 10) file << "0" << contact[i].date[0] << ".";
										else file << contact[i].date[0] << ".";
										if (contact[i].date[1] < 10) file << "0" << contact[i].date[1] << ".";
										else file << contact[i].date[1] << ".";
										file
											<< contact[i].date[2] << " "
											<< contact[i].code << " " << contact[i].city << " " << temp_time << " "
											<< contact[i].tarif << " " << contact[i].city_num << " " << contact[i].subscriber_num;
									}
									else {
										if (contact[i].date[0] < 10) file << "0" << contact[i].date[0] << ".";
										else file << contact[i].date[0] << ".";
										if (contact[i].date[1] < 10) file << "0" << contact[i].date[1] << ".";
										else file << contact[i].date[1] << ".";
										file << contact[i].date[2] << " " << contact[i].code << " " << contact[i].city << " ";
										if (contact[i].time[0] < 10) file << "0" << contact[i].time[0] << ".";
										else file << contact[i].time[0] << ".";
										if (contact[i].time[1] < 10) file << "0" << contact[i].time[1] << ".";
										else file << contact[i].time[1] << ".";
										if (contact[i].time[2] < 10) file << "0" << contact[i].time[2] << " ";
										else file << contact[i].time[2] << " ";
										file << contact[i].tarif << " " << contact[i].city_num << " " << contact[i].subscriber_num;
									}

									if (i != N - 1) {
										file << endl;
									}
								}
								cout << "Данные в файле обновлены!" << endl << endl;
								file.close();
							}
							else cout << "Данные в файле не были обновлены" << endl;
							temp_answ = 0;
						}
						else {
							cout << "Нет записи с таким номером" << endl;
							file.close();
						}
					}

					if (answer == 4) { //удалить запись из файла
						cout << "Исходный список: " << endl;
						OutputTableHead();
						OutputTableBody(contact, N);
						int index_number = 0;
						cout << "\nВведите порядковый номер записи, которую желаете удалить: ";
						cin >> index_number;
						cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
						cin >> temp_answ;
						if (temp_answ == 1) {
							for (int i = index_number - 1; i < N - 1; i++) {
								contact[i].date[0] = contact[i + 1].date[0];
								contact[i].date[1] = contact[i + 1].date[1];
								contact[i].date[2] = contact[i + 1].date[2];
								contact[i].code = contact[i + 1].code;
								contact[i].city = contact[i + 1].city;
								contact[i].time[0] = contact[i + 1].time[0];
								contact[i].time[1] = contact[i + 1].time[1];
								contact[i].time[2] = contact[i + 1].time[2];
								contact[i].tarif = contact[i + 1].tarif;
								contact[i].city_num = contact[i + 1].city_num;
								contact[i].subscriber_num = contact[i + 1].subscriber_num;
							}
							N--;
							cout << endl << "Новый список:" << endl;
							OutputTableBody(contact, N);

							ofstream file;
							file.open(file_name);
							for (int i = 0; i < N; i++) {
								if (contact[i].date[0] < 10) file << "0" << contact[i].date[0] << ".";
								else file << contact[i].date[0] << ".";
								if (contact[i].date[1] < 10) file << "0" << contact[i].date[1] << ".";
								else file << contact[i].date[1] << ".";
								file
									<< contact[i].date[2] << " "
									<< contact[i].code << " " << contact[i].city << " ";
								if (contact[i].time[0] < 10) file << "0" << contact[i].time[0] << ".";
								else file << contact[i].time[0] << ".";
								if (contact[i].time[1] < 10) file << "0" << contact[i].time[1] << ".";
								else file << contact[i].time[1] << ".";
								if (contact[i].time[2] < 10) file << "0" << contact[i].time[2] << " ";
								else file << contact[i].time[2] << " ";

								file << contact[i].tarif << " " << contact[i].city_num << " " << contact[i].subscriber_num;
								if (i != N - 1) file << "\n";
							}
							cout << "Данные в файле обновлены!" << endl;
							file.close();
						}
						else cout << "Данные в файле не были обновлены" << endl;
						temp_answ = 0;
					}

					if (answer == 5) {
						OutputTableBody(contact, N);
						QuickSort(contact, 0, N - 1);

						cout << endl << endl << "сортировка по коду города: " << endl;
						OutputTableHead();
						OutputTableBody(contact, N);
						cout << endl;
						int count = 1;
						for (i = 1; i < N; i++) {
							if (contact[i].code != contact[i - 1].code) count++;
						}

						memory* task = new memory[count];
						int j = 0;
						task[0].code = contact[0].code;
						task[0].city = contact[0].city;
						task[0].tarif = contact[0].tarif;
						task[0].time = contact[0].time[0] * 3600 + contact[0].time[1] * 60 + contact[0].time[2];
						task[0].sum += task[0].tarif * task[0].time;
						task[j].time_all[0] = task[j].time / 3600;
						task[j].time_all[1] = task[j].time % 3600;
						task[j].time_all[2] = task[j].time_all[1] % 60;
						task[j].time_all[1] = task[j].time_all[1] / 60;
						LinearSearch(contact, N, task, count);

						cout << endl << setw(6) << " code |" << setw(10) << " city |" << setw(8) << "tarif |" << setw(12) << "all time,s  |" << setw(11) << "hh.mm.ss |" << setw(11) << "sum |" << endl << "----------------------------------------------------------- " << endl;
						for (j = 0; j < count; j++) {
							cout << setw(6) << task[j].code << "|"
								<< setw(9) << task[j].city << "|"
								<< setw(7) << task[j].tarif << "|"
								<< setw(12) << task[j].time << "|";
							if (task[j].time_all[0] < 10)cout << setw(3) << "0" << task[j].time_all[0] << ".";
							else cout << setw(4) << task[j].time_all[0] << ".";
							if (task[j].time_all[1] < 10)cout << "0" << task[j].time_all[1] << ".";
							else cout << task[j].time_all[1] << ".";
							if (task[j].time_all[2] < 10)cout << "0" << task[j].time_all[2] << "|";
							else cout << task[j].time_all[2] << "|";
							cout << setw(10) << task[j].sum << "|" << endl;
						}
						cout << endl;

					}
				}
			}
		}
	}
}


// Сортировка и линейный поиск
void SortAndSearch(string file_name, int kod) {
	string temp_string;
	int N = 0;
	ifstream file;
	file.open(file_name);
	if (!file.is_open()) cout << "Ошибка. Файл не был открыт!" << endl;

	else {
		file.seekg(0);
		int oN = 0;
		string f_str;
		getline(file, f_str);
		if (f_str == "") cout << "Файл пуст!" << endl;
		else {
			file.seekg(0);
			while (!file.eof()) {					//	считаем количество строк в файле
				getline(file, temp_string, '\n');
				oN++;
			}
			N = oN;
			oN = 0;
			file.seekg(0);
			atc* contact = new atc[N]; // массив структур 
			int i = 0;
			string temp_d, temp_t;
			while (!file.eof() && i <= N - 1) { // вытягиваем данные с файла в массив структур
				file >> temp_d >> contact[i].code >> contact[i].city >> temp_t >> contact[i].tarif >> contact[i].city_num >> contact[i].subscriber_num;
				contact[i].date[0] = stoi(temp_d.substr(0, 2));
				contact[i].date[1] = stoi(temp_d.substr(3, 2));
				contact[i].date[2] = stoi(temp_d.substr(6, 4));

				contact[i].time[0] = stoi(temp_t.substr(0, 2));
				contact[i].time[1] = stoi(temp_t.substr(3, 2));
				contact[i].time[2] = stoi(temp_t.substr(6, 2));
				i++;
			}


			if (kod == 1) {	//	Сортировка
				int answer;
				cout << "Выберите тип сортировки (по коду города): \n1. Быстрая сортировка\n2. Метод прямого выбора" << endl;
				cin >> answer;
				bool flag = true;

				while (flag) {
					if (answer == 1 || answer == 2) {
						flag = false;
						//void OpenFileToEdit(string file_name) {
						if (answer == 1) {
							cout << "Быстрая сортировка" << endl;
							QuickSort(contact, 0, N - 1);
							OutputTableHead();
							OutputTableBody(contact, N);
						}

						else if (answer == 2) {
							cout << "Метод прямого выбора" << endl;
							DirectSelectionSorting(contact, N - 1);
							OutputTableHead();
							OutputTableBody(contact, N);
						}
					}

					else cout << "Неверный вариант ответа. Введите 1 или 2." << endl;
				}
			}

			if (kod == 2) {	//	Поиск
				QuickSort(contact, 0, N - 1);

				int count = 1;
				for (i = 1; i < N; i++) {
					if (contact[i].code != contact[i - 1].code) count++;
				}
				memory* task = new memory[count];
				int j = 0;
				task[0].code = contact[0].code;
				task[0].city = contact[0].city;
				task[0].tarif = contact[0].tarif;
				task[0].time = contact[0].time[0] * 3600 + contact[0].time[1] * 60 + contact[0].time[2];
				task[0].sum += task[0].tarif * task[0].time;
				task[j].time_all[0] = task[j].time / 3600;
				task[j].time_all[1] = task[j].time % 3600;
				task[j].time_all[2] = task[j].time_all[1] % 60;
				task[j].time_all[1] = task[j].time_all[1] / 60;

				LinearSearch(contact, N, task, count);// Линейный поиск (по коду города)
				cout << endl << setw(6) << " code |" << setw(10) << " city |" << setw(8) << "tarif |" << setw(12) << "all time,s  |" << setw(11) << "hh.mm.ss |" << setw(11) << "sum |" << endl << "----------------------------------------------------------- " << endl;
				for (j = 0; j < count; j++) {
					cout << setw(6) << task[j].code << "|"
						<< setw(9) << task[j].city << "|"
						<< setw(7) << task[j].tarif << "|"
						<< setw(12) << task[j].time << "|";
					if (task[j].time_all[0] < 10)cout << setw(3) << "0" << task[j].time_all[0] << ".";
					else cout << setw(4) << task[j].time_all[0] << ".";
					if (task[j].time_all[1] < 10)cout << "0" << task[j].time_all[1] << ".";
					else cout << task[j].time_all[1] << ".";
					if (task[j].time_all[2] < 10)cout << "0" << task[j].time_all[2] << "|";
					else cout << task[j].time_all[2] << "|";
					cout << setw(10) << task[j].sum << "|" << endl;
				}
				cout << endl;
			}
			file.close();
		}
	}
}


int main() {
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	int answer, N = 0, i = 0, key = 0, ans = 0;
	string file_name;

	while (1) {
		cout << "\n-------- МЕНЮ -----------" << endl;
		cout << "\n1. Создать файл\n2. Работа с существующим файлом\n3. Сортировка\n4. Линейный поиск\n\n0. Выход из программы" << endl;
		cin >> answer;

		if (answer == 0) exit(0);						//	Выход из программы

		else if (answer == 1 || answer == 2 || answer == 3 || answer == 4) {
			cout << "Введите имя фала (без .txt): ";
			cin >> file_name;
			file_name = file_name + ".txt";

			if (answer == 1) MakeFile(file_name);				//	Создать файл
			else if (answer == 2) EditFile(file_name);			//	Работа с существующим файлом
			else if (answer == 3) SortAndSearch(file_name, 1);	//	Сортировка
			else if (answer == 4) SortAndSearch(file_name, 2);	//	Поиск

		}

		else cout << "Неверный ответ!" << endl;
	}
	return 0;
}
