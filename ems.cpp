#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>

class Patient{
private:
    int patientId;
    std::string name;
    int injurySeverity;
    std::string requiredResource;
public:
    Patient(int p_id, std::string n, int is, std::string req_r)
            : patientId(p_id), name(n), injurySeverity(is), requiredResource(req_r){}

    int gtPatientId() const { return patientId; }
    std::string getName() const { return name; }
    int getInjurySeverity() const { return injurySeverity; }
    std::string getRequiredResource() const { return requiredResource; }


};

class Resource{
private:
    std::string resourceId;
    std::string type;
    bool isAvailable;
public:
    Resource(std::string r_id, std::string t, bool is_Av)
            : resourceId(r_id), type(t), isAvailable(is_Av){}
    std::string getResourceId() const { return resourceId; }
    std::string getType() const { return type; }
    bool getAvailability() const { return isAvailable; }
    void setAvailability(bool a){
        isAvailable = a;
    }
};

class CareStaff{
private:
    int staffId;
    std::string name;
    std::string specialization;
    bool isAssigned;
public:
    CareStaff(int s_id, std::string n, std::string spec, bool is_ass)
            : staffId(s_id), name(n), specialization(spec), isAssigned(is_ass){}

    int getStaffId() const { return staffId; }
    std::string getName() const { return name; }
    std::string getSpecialization() const { return specialization; }
    bool getAssignmentStatus() const { return isAssigned; }
};

struct ComparePatientSeverity{
    bool operator()(const Patient& a, const Patient& b)const {
        if(a.getInjurySeverity() != b.getInjurySeverity()){
            return a.getInjurySeverity() > b.getInjurySeverity();
        }
        return a.gtPatientId() < b.gtPatientId();
    }
};

class EMSSystem{
private:
    std::unordered_map<int , Patient> patients;
    std::map<std::string, Resource> resources;
    std::set<Patient, ComparePatientSeverity> triageQueue;
    std::vector<Patient> resolvedCases;
public:
    void registerPatient(const Patient& p){
        patients.insert({p.gtPatientId(), p});

        triageQueue.insert(p);
    }

    void addResource(const Resource& r){
        resources.insert({r.getResourceId(), r});
    }
    void printTriageQueue() const {
        std::cout << "--- CURRENT TRIAGE QUEUE (Highest Priority First) ---\n";
        for (const auto& patient : triageQueue) {
            std::cout << "ID: " << patient.gtPatientId() 
                      << " | Name: " << patient.getName() 
                      << " | Severity: " << patient.getInjurySeverity() << "\n";
        }
    }

    void processNextEmergency(){

        if(triageQueue.empty()){
            std::cout<<"No patients currently in the triage queue.\n";
            return;
        }
        auto patientIt = triageQueue.begin();
        Patient currentPatient = *patientIt;
        std::string reqType = currentPatient.getRequiredResource();

        bool resourcefound = false;

        for(auto& pair: resources){
            Resource& res = pair.second;
            if(res.getType() == reqType && res.getAvailability() == true){
                res.setAvailability(false);
                std::cout << "[DISPATCH SUCCESS] Patient " << currentPatient.getName() 
                      << " (Severity " << currentPatient.getInjurySeverity() << ")"
                      << " allocated to resource: " << res.getResourceId() << "\n";

                      resourcefound = true;
                      break;
            }
        }

        if(resourcefound){
            resolvedCases.push_back(currentPatient);
            triageQueue.erase(patientIt);
            patients.erase(currentPatient.gtPatientId());
        }else{
            std::cout << "[DISPATCH DELAY] No available " << reqType 
                  << " found for patient " << currentPatient.getName() 
                  << ". Holding in triage.\n";
        }
    }
    void printResolvedCases() const {
        std::cout << "--- RESOLVED CASES ARCHIVE (Audit Log) ---\n";
        if (resolvedCases.empty()) {
            std::cout << "No cases resolved yet.\n";
            return;
        }
        for (const auto& patient : resolvedCases) {
            std::cout << "Archived ID: " << patient.gtPatientId() 
                      << " | Name: " << patient.getName() 
                      << " | Status: DISPATCHED\n";
        }
    }
};

int main() {
    EMSSystem ems;
    std::cout << "=== Welcome to Emergency Medical Resource & Patient Tracker ===\n";
    int choice;

    while (true) {
        std::cout << "\n----------------------------------------\n";
        std::cout << "1. Admit Patient\n";
        std::cout << "2. Add Resource\n";
        std::cout << "3. Run Next Triage Dispatch\n";
        std::cout << "4. Show System Status (Queue & Archive)\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;
        std::cout << "----------------------------------------\n\n";

        if (choice == 5) {
            std::cout << "Exiting system. Stay safe!\n";
            break;
        }

        switch (choice) {
            case 1: {
                int id, severity;
                std::string name, reqResource;

                std::cout << "Enter Patient ID (integer): ";
                std::cin >> id;
                std::cin.ignore(); // Clears the newline character from the input buffer

                std::cout << "Enter Patient Name: ";
                std::getline(std::cin, name); // Captures full names with spaces

                std::cout << "Enter Injury Severity (1 = Minor, 5 = Critical): ";
                std::cin >> severity;
                std::cin.ignore();

                std::cout << "Enter Required Resource Type (e.g., ICU, Bed, Ventilator): ";
                std::getline(std::cin, reqResource);

                // Add to system
                ems.registerPatient(Patient(id, name, severity, reqResource));
                std::cout << "\n[SUCCESS] Patient successfully admitted to triage.\n";
                break;
            }
            case 2: {
                std::string resId, type;

                std::cout << "Enter Resource ID (e.g., ICU_BED_01): ";
                std::cin >> resId;
                std::cin.ignore();

                std::cout << "Enter Resource Type (e.g., ICU, Bed, Ventilator): ";
                std::getline(std::cin, type);

                // Add to system (defaulting availability to true)
                ems.addResource(Resource(resId, type, true));
                std::cout << "\n[SUCCESS] Resource added to inventory.\n";
                break;
            }
            case 3:
                std::cout << "Running Triage Dispatch Engine...\n\n";
                ems.processNextEmergency();
                break;

            case 4:
                ems.printTriageQueue();
                std::cout << "\n";
                ems.printResolvedCases();
                break;

            default:
                std::cout << "[ERROR] Invalid choice. Please select a number between 1 and 5.\n";
                break;
        }
    }

    return 0;
}