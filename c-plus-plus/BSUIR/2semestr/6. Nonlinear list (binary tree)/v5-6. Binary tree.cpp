#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Данные (ФИО и номера паспорта)
struct Data {
    string FIO;
    int passport = 0;
};


// Узел дерева
struct TreeNode {
    Data data;                      // Данные узла
    TreeNode* left = nullptr;       // Указатель на левого потомка
    TreeNode* right = nullptr;      // Указатель на правого потомка
};


// Создать узел дерева
TreeNode* CreateNode(const Data& data) {
    TreeNode* node = new TreeNode;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}


// Очистить дерево
void ClearTree(TreeNode*& root) {
    if (root == nullptr) return;
    // Рекурсивное удаление поддерева
    ClearTree(root->left);
    ClearTree(root->right);
    delete root;      // Освободить память текущего узла
    root = nullptr;   // Обнулить указатель
}


// Вставить новый узел в дерево
void InsertNode(TreeNode*& root, const Data& data) {
    if (root == nullptr) root = CreateNode(data);  // Создаем новый узел
    // Рекурсивный поиск места для вставки
    else if (data.passport < root->data.passport) InsertNode(root->left, data);  // Перейти в левое поддерево
    else InsertNode(root->right, data); // Перейти в правое поддерево
}


// Поиск узла по ключу
TreeNode* SearchNode(TreeNode* root, int key) {
    if (root == nullptr || root->data.passport == key) return root;
    // Рекурсивный поиск в поддеревьях
    if (key < root->data.passport)  return SearchNode(root->left, key);
    return SearchNode(root->right, key);
}


// Поиск узла с минимальным ключом в поддереве
TreeNode* FindMinValue(TreeNode* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}


// Удаление узла по ключу
TreeNode* DeleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;

    // Поиск удаляемого узла
    if (key < root->data.passport) root->left = DeleteNode(root->left, key);
    else if (key > root->data.passport) root->right = DeleteNode(root->right, key);
    else {
        if (root->left == nullptr) { // Нет левого потомка
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) { // Нет правого потомка
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Есть оба потомка
        TreeNode* temp = FindMinValue(root->right);  // Находим минимальный в правом поддереве
        root->data = temp->data;               // Копируем данные
        root->right = DeleteNode(root->right, temp->data.passport); // Удаляем дубликат
    }
    return root;
}


// Обход слева направо: Left - Root - Right
void LeftRootRight(TreeNode* root) {
    if (root != nullptr) {
        LeftRootRight(root->left);
        cout << root->data.passport << ": " << root->data.FIO << endl;
        LeftRootRight(root->right);
    }
}


// Обход сверху вниз: Root - Left - Right
void RootLeftRight(TreeNode* root) {
    if (root != nullptr) {
        cout << root->data.passport << ": " << root->data.FIO << endl;
        RootLeftRight(root->left);
        RootLeftRight(root->right);
    }
}


// Обход снизу вверх: Left - Right - Root
void LeftRightRoot(TreeNode* root) {
    if (root != nullptr) {
        LeftRightRoot(root->left);
        LeftRightRoot(root->right);
        cout << root->data.passport << ": " << root->data.FIO << endl;
    }
}


// Преобразование дерева в отсортированный массив
void ConvertTreeToArray(TreeNode* root, vector<Data>& arr) {
    if (root == nullptr) return;
    ConvertTreeToArray(root->left, arr);
    arr.push_back(root->data);
    ConvertTreeToArray(root->right, arr);
}


// Построение сбалансированного дерева из массива
TreeNode* BuildTreeFromArray(const vector<Data>& arr, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;  // Находим середину
    TreeNode* root = CreateNode(arr[mid]); // Создаем корень из среднего элемента
    // Рекурсивное построение поддеревьев
    root->left = BuildTreeFromArray(arr, start, mid - 1);
    root->right = BuildTreeFromArray(arr, mid + 1, end);
    return root;
}


// Балансировка дерева
void BalanceTree(TreeNode*& root) {
    vector<Data> arr;
    ConvertTreeToArray(root, arr);  // Преобразуем дерево в массив
    if (!arr.empty()) root = BuildTreeFromArray(arr, 0, (int)arr.size() - 1);
    else root = nullptr;
}


// ЗАДАНИЕ подсчёт количества узлов на каждом уровне
void CountNodes(TreeNode* root) {
    if (root == nullptr) {
        cout << "Дерево пустое.\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int levelSize = (int)q.size();  // Количество узлов на текущем уровне
        cout << "Уровень " << level << ": " << levelSize << " узлов\n";
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();
            // Добавление потомков в очередь
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        level++;  // Переход к следующему уровню
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    TreeNode* root = nullptr;      // Корень дерева
    int choice = 1;

    while (choice != 0) {
        cout << "\n\t1. Ввести данные из массива в дерево\n\t2. Сбалансировать дерево\n\t3. Добавить запись\n\t4. Найти информацию по ключу\n\t5. Удалить информацию по ключу\n\t6. Обход дерева\n\t7. ЗАДАНИЕ (подсчёт количества узлов на каждом уровне) \n\t0. Выход\n" << endl;
        cin >> choice;
        cin.ignore(); // чтобы убрать перевод строки после ввода
        switch (choice) {

        case 1: {  // Ввод данных из массива
            ClearTree(root);
            int n;
            cout << "Введите количество элементов: ";
            cin >> n;
            cin.ignore();

            for (int i = 0; i < n; i++) {
                Data data;
                cout << "Элемент " << i + 1 << ":\n";
                cout << ", ФИО: ";
                getline(cin, data.FIO);
                cout << ",  номер паспорта: ";
                cin >> data.passport;
                cin.ignore();
                InsertNode(root, data);
            }
            cout << "Данные добавлены.\n";
            break;
        }

        case 2: {  // Сбалансировать дерево
            if (root == nullptr) {
                cout << "Дерево пустое!\n";
            }
            else {
                BalanceTree(root);
                cout << "Дерево сбалансировано.\n";
            }
            break;
        }

        case 3: {  // Добавление новой записи
            Data data;
            cout << "Введите ФИО: ";
            getline(cin, data.FIO);
            cout << "Введите номер паспорта: ";
            cin >> data.passport;
            cin.ignore();
            InsertNode(root, data);
            cout << "Запись добавлена.\n";
            break;
        }

        case 4: {  // Поиск по ключу
            int key;
            cout << "Введите номер паспорта для поиска: ";
            cin >> key;
            cin.ignore();
            TreeNode* found = SearchNode(root, key);
            if (found != nullptr) cout << found->data.passport << " - " << found->data.FIO << endl;
            else cout << "Нет записей с таким номером паспорта.\n";
            break;
        }

        case 5: {  // Удаление по ключу
            int key;
            cout << "Введите номер паспорта для удаления: ";
            cin >> key;
            cin.ignore();
            root = DeleteNode(root, key);
            break;
        }
        case 6: {  // Обход дерева
            cout << "Выберите обход дерева:\n1. Слева направо. \n2. сверху вниз .\n3. CСнизу вверх.\n";
            int a = 0;
            cin >> a;
            cin.ignore();
            if (a == 1) LeftRootRight(root);
            else if (a == 2) RootLeftRight(root);
            else if (a == 3) LeftRightRoot(root);
            else cout << "Неверный ответ." << endl;
            break;
        }

        case 7: {  // ЗАДАНИЕ Поиск узлов с одним потомком
            CountNodes(root);
            break;
        }

        case 0:  exit(0);

        default: {
            cout << "Нет такого варианта ответа.\n";
            break;
        }
        }
    }
    ClearTree(root);  // Очистка памяти перед выходом
    return 0;
}
