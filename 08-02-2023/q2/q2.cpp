#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class SatelliteImage
{
    private:
        void path_find(vector<vector<int>> m, vector<int> coordinates, vector<vector<int>>& path)
        {
            cout << coordinates[0] << "|" << coordinates[1] << endl;
            if (m[coordinates[0]][coordinates[1]] > 0)
            {
                int found = 0;
                for (vector<int> coords : path)
                {
                    if (coords == coordinates) 
                    {
                        found = 1;
                        break;
                    }
                }
                if (found == 0) 
                {
                    path.push_back(coordinates);
                    if (coordinates[0] - 1 >= 0) path_find(m, vector<int>{coordinates[0]-1, coordinates[1]},path);
                    if (coordinates[1] - 1 >= 0) path_find(m, vector<int>{coordinates[0], coordinates[1]-1},path);
                    if (coordinates[0] + 1 < m.size()) path_find(m, vector<int>{coordinates[0]+1, coordinates[1]},path);
                    if (coordinates[1] + 1 < m[0].size()) path_find(m, vector<int>{coordinates[0], coordinates[1]+1},path);
                    //
                    if (coordinates[0] + 1 < m.size() && coordinates[1] + 1 < m[0].size()) path_find(m, vector<int>{coordinates[0]+1, coordinates[1]+1},path);
                    if (coordinates[0] - 1 >= 0 && coordinates[1] - 1 >= 0) path_find(m, vector<int>{coordinates[0]-1, coordinates[1]-1},path);
                    if (coordinates[0] - 1 >= 0 && coordinates[1] + 1 < m[0].size()) path_find(m, vector<int>{coordinates[0]-1, coordinates[1]+1},path);
                    if (coordinates[0] + 1 < m.size() && coordinates[1] - 1 >= 0) path_find(m, vector<int>{coordinates[0]+1, coordinates[1]-1},path);
                }
                
            }
        }

    public:
        vector<vector<int>> image_matrix;

        int get_construction_amount()
        {
            vector<vector<vector<int>>> paths;
            for (int i = 0; i < image_matrix.size(); i++)
            {
                for (int j = 0; j < image_matrix[0].size(); j++)
                {
                    vector<vector<int>> path;
                    path_find(image_matrix, vector<int>{i, j}, path);
                    sort(path.begin(), path.end());
                    int hasPath = 0;
                    for (vector<vector<int>> p : paths)
                    {
                        if (p == path) hasPath = 1;
                    } 
                    if (hasPath == 0 && path.size() != 0) paths.push_back(path);
                }
            }
            return paths.size();
            
        }

        void fget_construction_amount(string file_name, string file_name_out)
        {
            ifstream image_file(file_name);
            ofstream image_out(file_name_out);
            string string_buffer;
            int i = 0;
            while (true)
            {
                getline(image_file, string_buffer, ' ');
                if (string_buffer[0] == '0') break;
                cout << "Line: " << string_buffer << endl;
                int lines = stoi(string_buffer);
                cout << "Lines: " << lines << endl;
                image_out << "Teste " << i++ << endl;
                vector<vector<int>> img;
                getline(image_file, string_buffer);
                for (int j = 0; j < lines; j++)
                {
                    getline(image_file, string_buffer);
                    vector<int> line;
                    for (char c : string_buffer) line.push_back(int(c)-48);
                    img.push_back(line);
                }
                image_matrix = img;
                for (int i = 0; i < img.size(); i++)
                {
                    for (int j = 0; j < img[0].size(); j++)
                    {
                        cout << img[i][j];
                    }
                    cout << endl;
                }
                image_out << "Número de construções: " << get_construction_amount() << endl;
                image_out << '\n';
                if (i > 1000) break;
            }
        }
};

int main()
{
    SatelliteImage sImage;
    sImage.fget_construction_amount("imagem.in", "imagem.out");
    return 0;
}