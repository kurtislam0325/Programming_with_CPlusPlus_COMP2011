#include <iostream>
#include <fstream>

using namespace std;

// question: difference of eof

// Do not change this function. It is used for checking the lab.
void prepare_files(){
    ofstream ofs ("student_list.txt");

    if (ofs){
        ofs << 20185639 << endl;
        ofs << 22435497 << endl;
        ofs << 23143658 << endl;
        ofs << 29372413 << endl;
        ofs << 29567638 << endl;
        ofs << 29576389 << endl;
    }
}


// Do not change this function. It is used for checking the lab.
void check_final_list(){
    ifstream ifs ("student_list.txt");
    if (ifs){
        int line;
        while (ifs >> line){
            cout << line << endl;
        }
        ifs.close();
    }
}


// TODO: search for a student in the input file, student_list.txt, return true if found.
bool student_lookup(int student_id){
    ifstream ifs ("student_list.txt");
    if (ifs){
        int line;
        while (ifs >> line){
            if (line == student_id)
                return true;
        }
        ifs.close();
    }
    return false;
}


// TODO: delete a student id from the input file.
// The result should not contain blank lines
// Please check the section "Hint" in the lab page for how to rename a file or remove a file.
void delete_student(int student_id){
    if (student_lookup(student_id) == false) 
    {
        cout << "Student " << student_id << " is not taking the course!" << endl;
    }
    else 
    {
        ifstream ifs ("student_list.txt");
        ofstream ofs ("temp.txt");

        int file_data;
        ifs >> file_data;
        while (!ifs.eof())
        {
            if (file_data != student_id)
                ofs << file_data << "\n";

            ifs >> file_data;
        };  

        remove("student_list.txt");
        rename("temp.txt","student_list.txt");

        if (student_lookup(student_id) == false) 
            cout << "Student " << student_id << " is removed from the course!" << endl;
        
        ifs.close(); ofs.close();       
    }

}


// TODO: insert a student in the input file such that the student ids are in ascending order
// It should not insert duplicate student id.
// Please check the section "Hint" in the lab page for how to rename a file or remove a file.
void insert_student(int student_id){
    if (student_lookup(student_id) == true) 
    {
        cout << "Student " << student_id << " is already taking the course!" << endl;
    }
    else
    {
        ifstream ifs ("student_list.txt");
        ofstream ofs ("temp.txt");

        const int array_size = 128;
        int file_data_array[array_size];
        int num_student = 0;

        if (ifs)
        {
            while (ifs >> file_data_array[num_student])
                num_student++;
        }

        file_data_array[num_student] = student_id;

        for (int j = num_student; j > 0; j--)
        {
            if (file_data_array[j] < file_data_array[j-1])
            {
                int temp = file_data_array[j];
                file_data_array[j] = file_data_array[j-1];
                file_data_array[j-1] = temp;
            }
        }   

        for (int j = 0; j <= num_student; j++)
            ofs << file_data_array[j] << endl;

        remove("student_list.txt");
        rename("temp.txt","student_list.txt");
        if (student_lookup(student_id) == true) 
            cout << "Student " << student_id << " is inserted successfully!" << endl;

        ifs.close(); ofs.close();
    }
}

int main()
{
    const char filename[] = "student_list.txt";
    char choice;
    int student_id;

    prepare_files();

    while (true){       

        cout << "1 for lookup; 2 for insertion; 3 for deletion; q for quit: ";
        cin >> choice;

        if (choice == '1'){
            cout << "Please enter the id of the student you want to search for: ";
            cin >> student_id;
            if (student_lookup(student_id)){
                cout << "Student " << student_id << " is found!" << endl;
            }else{
                cout << "Student " << student_id << " is not found!" << endl;
            }
        }else if (choice == '2'){
            cout << "Please enter the id of the student you want to insert: ";
            cin >> student_id;
            insert_student( student_id);
        }else if (choice == '3'){
            cout << "Please enter the id of the student you want to delete: ";
            cin >> student_id;
            delete_student(student_id);
        }else if (choice == 'q'){
            check_final_list();
            break;
        }else{
            cout << "Invalid input. Please input again." << endl;
        }
        cout << endl;
    }

    return 0;
}