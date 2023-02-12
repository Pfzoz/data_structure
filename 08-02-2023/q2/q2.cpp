#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class SatelliteImage
{
    private:
        void path_find(vector<vector<int>> m, vector<int> coordinates, vector<vector<int>>& path)
        {
            if (m[coordinates[0]][coordinates[1]] > 0)
            {
                int found = 0;
                for (vector<int> coords : path)
                {
                    if (coords == coordinates) found = 1;
                }
                if (found == 0) path.push_back(coordinates);
                if (coordinates[0] - 1 >= 0) path_find(m, vector<int>{coordinates[0]-1, coordinates[1]},path);
                if (coordinates[1] - 1 >= 0) path_find(m, vector<int>{coordinates[0], coordinates[1]-1},path);
                if (coordinates[0] + 1 < m.size()) path_find(m, vector<int>{coordinates[0]+1, coordinates[1]},path);
                if (coordinates[1] + 1 < m[0].size()) path_find(m, vector<int>{coordinates[0], coordinates[1]+1},path);
                //
                if (coordinates[0] + 1 < m.size() && coordinates[1] + 1 < m[0].size()) path_find(m, vector<int>{coordinates[0]+1, coordinates[1]+1},path);
                if (coordinates[0] - 1 >= 0 && coordinates[1] - 1 >= 0) path_find(m, vector<int>{coordinates[0]-1, coordinates[1]-1},path);
                if (coordinates[0] - 1 >= 0 && coordinates[1] + 1 < m[0].size()) path_find(m, vector<int>{coordinates[0]-1, coordinates[1]+1},path);
                if (coordinates[0] + 1 >= 0 && coordinates[1] - 1 >= 0) path_find(m, vector<int>{coordinates[0]+1, coordinates[1]-1},path);

            }
        }

    public:
        vector<vector<int>> image_matrix;

        SatelliteImage(vector<vector<int>> image)
        {
            image_matrix = image;
        }

        int get_construction_amount()
        {
            vector<int> searched_indexes;
            int constructions = 0;
            
        }

        void fget_construction_amount(string file_name, string file_name_out)
        {
            ifstream image_file(file_name);
            ofstream image_out(file_name_out);
            string string_buffer;
            int i = 0;
            while (true)
            {
                getline(image_file, string_buffer);
                if (string_buffer[0] == '0') break;
                int lines = stoi(string_buffer.substr(0, string_buffer.find(' ')));
                image_out << "Teste " << i++ << endl;
                vector<vector<int>> img;
                for (int j = 0; j < lines; j++)
                {
                    getline(image_file, string_buffer);
                    vector<int> line;
                    for (char c : string_buffer) line.push_back(int(c));
                    img.push_back(line);
                }
                image_matrix = img;
                image_out << "Número de construções: " << get_construction_amount() << endl;
                image_out << '\n';
                if (i > 1000) break;
            }
        }
};

int main()
{
    
    return 0;
}