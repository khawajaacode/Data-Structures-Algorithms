#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// Structure to store movie info
struct MovieInfo {
    string movieName;
    string actorName;
    int year;
    string genre;
};

// BST node structure
struct BSTNode {
    string key; // lowercase actor or movie name
    MovieInfo info;
    BSTNode* left;
    BSTNode* right;

    BSTNode(string k, MovieInfo m) : key(k), info(m), left(nullptr), right(nullptr) {}
};

// Convert string to lowercase for case-insensitive search
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Insert node into BST
BSTNode* insert(BSTNode* root, string key, MovieInfo info) {
    if (root == nullptr) return new BSTNode(key, info);

    if (key < root->key)
        root->left = insert(root->left, key, info);
    else if (key > root->key)
        root->right = insert(root->right, key, info);

    return root;
}

// Search node in BST
BSTNode* search(BSTNode* root, string key) {
    if (root == nullptr || root->key == key) return root;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Load data from movies.txt
void loadData(BSTNode*& root, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find("|");
        size_t pos2 = line.find("|", pos1 + 1);
        size_t pos3 = line.find("|", pos2 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) continue;

        MovieInfo info;
        info.movieName = line.substr(0, pos1);
        info.actorName = line.substr(pos1 + 1, pos2 - pos1 - 1);
        info.year = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        info.genre = line.substr(pos3 + 1);

        string actorKey = toLower(info.actorName);
        string movieKey = toLower(info.movieName);

        // Index by both actor and movie names
        root = insert(root, actorKey, info);
        root = insert(root, movieKey, info);
    }

    file.close();
}

// Display movie info
void printInfo(MovieInfo info) {
    cout << "Movie: " << info.movieName << endl;
    cout << "Actor: " << info.actorName << endl;
    cout << "Year: " << info.year << endl;
    cout << "Genre: " << info.genre << endl;
}

// Main driver
int main() {
    BSTNode* root = nullptr;
    loadData(root, "movies.txt");

    cout << "\n--- Movie/Actor Search ---\n";
    while (true) {
        string query;
        cout << "\nEnter movie/actor name to search (or 'exit' to quit): ";
        getline(cin, query);

        if (query == "exit") break;

        string key = toLower(query);
        BSTNode* result = search(root, key);

        if (result) {
            cout << "\n--- Found ---\n";
            printInfo(result->info);
        } else {
            cout << "\nNot Found.\n";
        }
    }

    return 0;
}
