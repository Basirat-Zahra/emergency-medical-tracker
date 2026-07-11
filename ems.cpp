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
    ems.addResource(Resource("ICU_BED_01", "ICU", true));
    ems.addResource(Resource("ICU_BED_02", "ICU", true));
    ems.addResource(Resource("GEN_BED_01", "Bed", true));
    // Register patients out of order
    ems.registerPatient(Patient(101, "Alice (Broken Leg)", 3, "Bed"));
    ems.registerPatient(Patient(102, "Bob (Heart Attack)", 5, "ICU"));
    ems.registerPatient(Patient(103, "Charlie (Minor Cut)", 1, "Bandage"));
    ems.registerPatient(Patient(104, "David (Severe Trauma)", 5, "ICU"));

    // Check if the custom comparator sorted them correctly!
    ems.printTriageQueue();
    std::cout<<"\n--- STARTING DISPATCH PROCESSING ---\n";
    ems.processNextEmergency();;
    ems.processNextEmergency();;
    ems.processNextEmergency();;
    std::cout<<"\n";
    ems.printTriageQueue();
    std::cout<<"\n";
    ems.printResolvedCases();

    return 0;
}