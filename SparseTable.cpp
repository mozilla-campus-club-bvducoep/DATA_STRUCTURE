#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void Print_SparseTable (vector<vector<int>>& sparse_table) {

     int rows = sparse_table.size();
     int cols = sparse_table[0].size();

     cout << "Sparse table..." << endl;
     cout << "---------------" << endl;
     for (int r=0; r<rows; r++) {
         for (int c=0; c<cols; c++) {
             cout << sparse_table[r][c] << " ";
         } cout << endl;
     }
     cout << "---------------" << endl;
}

void Build_SparseTable (vector<int>& vec, vector<vector<int>>& sparse_table) {

     int rows = vec.size();
     int cols = sparse_table[0].size();

     for (int r=0; r<rows; r++)
         sparse_table[r][0] = vec[r];

     for (int c=1; c <= cols; c++) {
         int range = (1 << c);
         /* For  c    Range     c-1  Previous Range
                 1   2^1 = 2     0      2^0 = 1 
                 2   2^2 = 4     1      2^1 = 2
                 3   2^3 = 8     2      2^2 = 4
                 ...         */
         for (int r=0; r + range <= rows; r++) {
             // Values in the current column are derived from the        
             // values in the previous column.                          
             sparse_table[r][c] = min (sparse_table[r][c-1],
                                       sparse_table[r+(1<<(c-1))][c-1]);
         }
     }

     Print_SparseTable(sparse_table);
}

int RMQ (int left, int right, vector<vector<int>>& sparse_table) {

    // Find the biggest block of size 2^p that fits in the range "left" till "right".

    int power_of_2 = (int) log2( right + 1 - left );
    int x = right + 1 - ( 1 << power_of_2 );

    cout << "Left : " << left << " Right : " << right << endl;
    cout << "Part 1: (" << left << ".." << left + ( 1 << power_of_2 ) - 1 << ")" << " Part 2: (" << right + 1 - ( 1 << power_of_2 ) << ".." << right << ")" << endl;

    if ( sparse_table[left][power_of_2] <= sparse_table[right + 1 - ( 1 << power_of_2 )][power_of_2] )
        return sparse_table[left][power_of_2];
    else
        return sparse_table[right + 1 - ( 1 << power_of_2)][power_of_2];
}

int main()
{
    vector<int> vec = { 4, 6, 8, 7, 3, 2, 9, 5, 1};

    cout << "Index : ";
    for (int i=0; i<vec.size(); i++) {
        cout << i << " ";
    } cout << endl;

    cout << "Array : ";
    for (auto& it : vec) {
        cout << it << " ";
    } cout << endl;

    // Calculate the column size required for creating the sparse table
    // Columns = log2 (number_count) + 1; log2(x) can also be calculated as log2(x) = log(x)/log(2) + 1
    int sz = ceil (log2 (vec.size()) ) + 1;

    // Create a sparse table of size [number_count][ceil ( log2 (number_count)) + 1]
    vector<vector<int>> sparse_table (vec.size(), vector<int>(sz));

    Build_SparseTable (vec, sparse_table);

    cout << "Range Minium Queries (2, 7) : " <<  RMQ (2, 7, sparse_table) << endl << endl;
    cout << "Range Minium Queries (0, 2) : " <<  RMQ (0, 2, sparse_table) << endl << endl;
    cout << "Range Minium Queries (0, 8) : " <<  RMQ (0, 8, sparse_table) << endl << endl;
    cout << "Range Minium Queries (4, 5) : " <<  RMQ (4, 5, sparse_table) << endl << endl;
    cout << "Range Minium Queries (7, 8) : " <<  RMQ (7, 8, sparse_table) << endl << endl;
    cout << "Range Minium Queries (1, 4) : " <<  RMQ (1, 4, sparse_table) << endl << endl;

    return 0;
}
