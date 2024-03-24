#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure for patient record
struct Patient {
    int id;
    string name;
    int age;
    string gender;
};

// Structure for doctor record
struct Doctor {
    int id;
    string name;
    string specialization;
};

// Function to add a patient record
void addPatientRecord(vector<Patient>& patients) {
    Patient patient;

    cout << "Enter patient ID: ";
    cin >> patient.id;
    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, patient.name);
    cout << "Enter patient age: ";
    cin >> patient.age;
    cout << "Enter patient gender: ";
    cin.ignore();
    getline(cin, patient.gender);

    patients.push_back(patient);

    cout << "Patient record added successfully." << endl;
}

// Function to search for a patient record

void searchPatientRecord(const vector<Patient>& patients, int id) {
    auto it = find_if(patients.begin(), patients.end(), [id](const Patient& patient) {
        return patient.id == id;
    });
    if (it != patients.end()) {
        cout << "Patient ID: " << it->id << endl;
        cout << "Patient Name: " << it->name << endl;
        cout << "Patient Age: " << it->age << endl;
        cout << "Patient Gender: " << it->gender << endl;
    } else {
        cout << "Patient record not found." << endl;
    }
}

// Function to update a patient record
void updatePatientRecord(vector<Patient>& patients, int id) {
    auto it = find_if(patients.begin(), patients.end(), [id](const Patient& patient) {
        return patient.id == id;
    });

    if (it != patients.end()) {
        cout << "Enter new patient name: ";
        cin.ignore();
        getline(cin, it->name);
        cout << "Enter new patient age: ";
        cin >> it->age;
        cout << "Enter new patient gender: ";
        cin.ignore();
        getline(cin, it->gender);

        cout << "Patient record updated successfully." << endl;
    } else {
        cout << "Patient record not found." << endl;
    }
}

// Function to delete a patient record
void deletePatientRecord(vector<Patient>& patients, int id) {
    auto it = find_if(patients.begin(), patients.end(), [id](const Patient& patient) {
        return patient.id == id;
    });

    if (it != patients.end()) {
        patients.erase(it);
        cout << "Patient record deleted successfully." << endl;
    } else {
        cout << "Patient record not found." << endl;
    }
}

// Function to add a doctor record
void addDoctorRecord(vector<Doctor>& doctors) {
    Doctor doctor;

    cout << "Enter doctor ID: ";
    cin >> doctor.id;
    cout << "Enter doctor name: ";
    cin.ignore();
    getline(cin, doctor.name);
    cout << "Enter doctor specialization: ";
    cin.ignore();
    getline(cin, doctor.specialization);

    doctors.push_back(doctor);

    cout << "Doctor record added successfully." << endl;
}

// Function to search for a doctor record
void searchDoctorRecord(const vector<Doctor>& doctors, int id) {
    auto it = find_if(doctors.begin(), doctors.end(), [id](const Doctor& doctor) {
        return doctor.id == id;
    });

    if (it != doctors.end()) {
        cout << "Doctor ID: " << it->id << endl;
        cout << "Doctor Name: " << it->name << endl;
        cout << "Doctor Specialization: " << it->specialization << endl;
    } else {
        cout << "Doctor record not found." << endl;
    }
}

// Function to update a doctor record
void updateDoctorRecord(vector<Doctor>& doctors, int id) {
    auto it = find_if(doctors.begin(), doctors.end(), [id](const Doctor& doctor) {
        return doctor.id == id;
    });

    if (it != doctors.end()) {
        cout << "Enter new doctor name: ";
        cin.ignore();
        getline(cin, it->name);
        cout << "Enter new doctor specialization: ";
        cin.ignore();
        getline(cin, it->specialization);

        cout << "Doctor record updated successfully." << endl;
    } else {
        cout << "Doctor record not found." << endl;
    }
}

// Function to delete a doctor record
void deleteDoctorRecord(vector<Doctor>& doctors, int id) {
    auto it = find_if(doctors.begin(), doctors.end(), [id](const Doctor& doctor) {
        return doctor.id == id;
    });

    if (it != doctors.end()) {
        doctors.erase(it);
        cout << "Doctor record deleted successfully." << endl;
    } else {
        cout << "Doctor record not found." << endl;
    }
}

// Function to save patient records to a file
void savePatientRecords(const vector<Patient>& patients, const string& filename) {
    ofstream outputFile(filename);

    for (const Patient& patient : patients) {
        outputFile << patient.id << "," << patient.name << "," << patient.age << "," << patient.gender << endl;
    }

    outputFile.close();
}

// Function to save doctor records to a file
void saveDoctorRecords(const vector<Doctor>& doctors, const string& filename) {
    ofstream outputFile(filename);

    for (const Doctor& doctor : doctors) {
        outputFile << doctor.id << "," << doctor.name << "," << doctor.specialization << endl;
    }

    outputFile.close();
}

// Function to load patient records from a file
// void loadPatientRecords(vector<Patient>& patients, const string& filename) {
//     ifstream inputFile(filename);

//     if (!inputFile) {
//         cout << "Failed to open file: " << filename << endl;
//         return;
//     }

//     patients.clear();

//     string line;
//     while (getline(inputFile, line)) {
//         stringstream ss (line);
//         string token;

//         Patient patient;

//         getline(ss, token, ',');
//         patient.id = stoi(token);

//         getline(ss, token, ',');
//         patient.name = token;

//         getline(ss, token, ',');
//         patient.age = stoi(token);

//         getline(ss, token);
//         patient.gender = token;

//         patients.push_back(patient);
//     }

//     inputFile.close();
// }

// Function to load doctor records from a file
// void loadDoctorRecords(vector<Doctor>& doctors, const string& filename) {
//     ifstream inputFile(filename);

//     if (!inputFile) {
//         cout << "Failed to open file: " << filename << endl;
//         return;
//     }

//     doctors.clear();

//     string line;
//     while (getline(inputFile, line)) {
//         stringstream ss(line);
//         string token;

//         Doctor doctor;

//         getline(ss, token, ',');
//         doctor.id = stoi(token);

//         getline(ss, token, ',');
//         doctor.name = token;

//         getline(ss, token);
//         doctor.specialization = token;

//         doctors.push_back(doctor);
//     }

//     inputFile.close();
// }

int main() {
    vector<Patient> patients;
    vector<Doctor> doctors;

    // Load patient and doctor records from files
    // loadPatientRecords(patients, "patients.txt");
    // loadDoctorRecords(doctors, "doctors.txt");

    int choice;

    while (true) {
        cout << "==== Hospital Management System ====" << endl;
        cout << "1. Add Patient Record" << endl;
        cout << "2. Search Patient Record" << endl;
        cout << "3. Update Patient Record" << endl;
        cout << "4. Delete Patient Record" << endl;
        cout << "5. Add Doctor Record" << endl;
        cout << "6. Search Doctor Record" << endl;
        cout << "7. Update Doctor Record" << endl;
        cout << "8. Delete Doctor Record" << endl;
        cout << "9. Save Records" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatientRecord(patients);
                break;
            case 2:
                int patientId;
                cout << "Enter patient ID to search: ";
                cin >> patientId;
                searchPatientRecord(patients, patientId);
                break;
            case 3:
                int updatePatientId;
                cout << "Enter patient ID to update: ";
                cin >> updatePatientId;
                updatePatientRecord(patients, updatePatientId);
                break;
            case 4:
                int deletePatientId;
                cout << "Enter patient ID to delete: ";
                cin >> deletePatientId;
                deletePatientRecord(patients, deletePatientId);
                break;
            case 5:
                addDoctorRecord(doctors);
                break;
            case 6:
                int doctorId;
                cout << "Enter doctor ID to search: ";
                cin >> doctorId;
                searchDoctorRecord(doctors, doctorId);
                break;
            case 7:
                int updateDoctorId;
                cout << "Enter doctor ID to update: ";
                cin >> updateDoctorId;
                updateDoctorRecord(doctors, updateDoctorId);
                break;
            case 8:
                int deleteDoctorId;
                cout << "Enter doctor ID to delete: ";
                cin >> deleteDoctorId;
                deleteDoctorRecord(doctors, deleteDoctorId);
                break;
            case 9:
                savePatientRecords(patients, "patients.txt");
                saveDoctorRecords(doctors, "doctors.txt");
                cout << "Records saved successfully." << endl;
                break;
            case 10:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
