// files.cpp :уровень 1
// вычислить общий средний балл всех студентов и вывести инфу про студентов инетересующей группы с средним баллом выше среднего
//

#include <iostream>
#include <fstream>

#include <iomanip>
#include <string>

using namespace std;

struct Students {
	string surname;                 // фамилия
	string name;					// имя
	string middle_name;				// отчество
	int group = 0;					// номер группы(ключ 1)
	string post;                    // должность
	int grades[3] = { 0, 0, 0 };	// оценки (физика, математика, информатика, средний балл)
	float sr_bal = 0.;
};


void OutputTable(Students s[], int N) {
	cout << setw(5) << left << "  #"
		<< setw(20) << left << "Фамилия" << "|"
		<< setw(20) << "Имя" << "|"
		<< setw(25) << "Отчество" << "|"
		<< setw(9) << "№ группы" << "|"
		<< right << setw(6) << "физ" << "|"
		<< right << setw(6) << "мат" << "|"
		<< right << setw(6) << "инф" << "|"
		<< right << setw(6) << "средний балл" << "|" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < N; i++) {
		//s[i].sr_bal = (s[i].grades[0] + s[i].grades[1] + s[i].grades[2]) / 3.;
		cout << setw(3) << right << i + 1 << setw(2) << left << "."
			<< setw(20) << left << s[i].surname << "|"
			<< setw(20) << s[i].name << "|"
			<< setw(25) << s[i].middle_name << "|"
			<< setw(9) << s[i].group << "|"
			<< right << setw(6) << s[i].grades[0] << "|"
			<< right << setw(6) << s[i].grades[1] << "|"
			<< right << setw(6) << s[i].grades[2] << "|"
			<< right << setw(6) << s[i].sr_bal << "|" << endl;
	}
}


void LinearSearch(Students s[], int N, float x, float ball) {					// x - средний балл
	int k = 0;
	int temp = 0;
	for (int i = 0; i < N; i++) {
		//s[i].sr_bal = (s[i].grades[0] + s[i].grades[1] + s[i].grades[2]) / 3.;
		if (s[i].group==x) {
			if (s[i].sr_bal > ball) {
				if (temp == 0) {

					cout << setw(5) << left << "  #"
						<< setw(20) << left << "Фамилия" << "|"
						<< setw(20) << "Имя" << "|"
						<< setw(25) << "Отчество" << "|"
						<< setw(9) << "№ группы" << "|"
						<< right << setw(6) << "физ" << "|"
						<< right << setw(6) << "мат" << "|"
						<< right << setw(6) << "инф" << "|"
						<< right << setw(6) << "средний балл" << "|" << endl;
					cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				}
				cout << setw(3) << right << i + 1 << setw(2) << left << "."
					<< setw(20) << left << s[i].surname << "|"
					<< setw(20) << s[i].name << "|"
					<< setw(25) << s[i].middle_name << "|"
					<< setw(9) << s[i].group << "|"
					<< right << setw(6) << s[i].grades[0] << "|"
					<< right << setw(6) << s[i].grades[1] << "|"
					<< right << setw(6) << s[i].grades[2] << "|"
					<< right << setw(6) << s[i].sr_bal << "|" << endl;
				k++;
				temp++;
			}
		}
	}
	if (k == 0) {
		cout << "Нет таких студентов." << endl;
	}
}


void FileEdition(string file_name) {
	int loop = 1;
	while (loop == 1) {
		int temp_answ = 0;
		int answer = 0;
		string temp_string;
		cout << "\nРедактирование файла " << file_name << ":\n1. просмотр файла\n2. Добавить запись в файл\n3. Задание\n\n0. Выход в главное меню\n\n";
		cin >> answer;
		if (answer == 0) {
			loop = 0;
		}
		if (answer == 2) {
			int answer1 = 1;

			ofstream file;                                                 // поток записи в файл
			file.open(file_name, ios::app);                                // открыть файл в режиме app, чтобы указатель переместился в конец файла и предыдущие данные не стерлись
			if (!file.is_open()) {
				cout << "Ошибка. Файл не был открыт!" << endl;
			}
			else {
				string t_surname, t_name, t_middlename;
				int t_group = 0, t_phys = 0, t_math = 0, t_inf = 0;
				float t_sr_ball = 0.;
				answer1 = 1;
				while (answer1 == 1) {
					cout << "Фамилия: " << endl;
					cin >> t_surname;
					cout << "Имя: " << endl;
					cin >> t_name;
					cout << "Отчество: " << endl;
					cin >> t_middlename;
					cout << "Номер группы: " << endl;
					cin >> t_group;
					cout << "Оценка по физике: " << endl;
					cin >> t_phys;
					cout << "Оценка по математике: " << endl;
					cin >> t_math;
					cout << "Оценка по информатике: " << endl;
					cin >> t_inf;
					t_sr_ball = (t_phys + t_math + t_inf) / 3.;
					cout << "Сохранить изменения в файле?\n1 - да,\n 2 - нет" << endl;
					cin >> temp_answ;
					if (temp_answ == 1) {
						file << "\n" << t_surname << " " << t_name << " " << t_middlename << " " << t_group << " " << t_phys << " " << t_math << " " << t_inf << " " << t_sr_ball;
					}
					else cout << "Данные не были добавлены в файл!" << endl;
					cout << "Желаете добавить еще запись? \n1 - да\n2 - нет" << endl;
					cin >> answer1;
					if (answer1 == 1) file << "\n";
				}
				file.close();
			}
		}

		if (answer == 1 || answer == 3) {

			int N = 0;
			ifstream file;
			file.open(file_name);
			if (!file.is_open()) cout << "Ошибка. Файл не был открыт!" << endl;

			else {
				file.seekg(0);
				int oN = 0;
				string f_str;
				getline(file, f_str);
				if (file.eof() || f_str == "") cout << "Файл пуст!" << endl;
				else {
					file.seekg(0);
					while (!file.eof()) {
						getline(file, temp_string, '\n');
						oN++;
					}
					N = oN;
					oN = 0;
					file.seekg(0);
					Students* s = new Students[N];
					int i = 0;
					float s_ball = 0.;
					while (!file.eof() && i <= N - 1) {
						file >> s[i].surname >> s[i].name >> s[i].middle_name >> s[i].group >> s[i].grades[0] >> s[i].grades[1] >> s[i].grades[2] >> s[i].sr_bal; //= (s[i].grades[0] + s[i].grades[1] + s[i].grades[2]) / 3.;
						s_ball += s[i].sr_bal;
						i++;
					}
					s_ball = s_ball / N;
					file.close();
					i = 0;
					if (answer == 1) {
						OutputTable(s, N);
					}

					if (answer == 3) {
						cout << "Введите номер группы, о которой желаете получить информацию: " << endl;
						int x = 0;
						cin >> x;
						LinearSearch(s, N, x, s_ball);
					}
				}
			}
		}
	}
}


int main() {
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	int answer, N = 0, i = 0;
	string file_name, temp_string;
	while (1) {
		cout << "\n-------- МЕНЮ -----------" << endl;
		cout << "\n1. Создать файл\n2. Работа с существующим файлом\n3. Выход из программы" << endl;
		cin >> answer;
		if (answer == 3) exit(0);
		cout << "Введите имя фала: ";
		cin >> file_name;
		file_name = file_name + ".txt";
		if (answer == 1) {
			ofstream file;
			file.open(file_name);
			if (!file.is_open()) {
				cout << "Ошибка. Файл не был открыт!" << endl;
			}
			else {
				cout << "Файл был создан." << endl;
				file.close();
			}
		}
		if (answer == 2) {
			FileEdition(file_name);
		}
	}
	return 0;
}
