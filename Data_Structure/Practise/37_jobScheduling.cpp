#include <bits/stdc++.h>
using namespace std;

// A class to represent a job
class Job {
public:
    int id;       // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit if the job is completed before or on the deadline

    // Constructor
    Job(int id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }

    // Static function to sort jobs in descending order of profit
    static bool compare(Job a, Job b) {
        return a.profit > b.profit;
    }
};

// Function to schedule jobs to maximize profit
void jobScheduling(vector<Job> &jobs, int n) {
    // Sort all jobs according to their profit in descending order
    sort(jobs.begin(), jobs.end(), Job::compare);

    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Create an array to keep track of free time slots
    vector<int> slots(maxDeadline + 1, -1); // Initialize all slots as free

    int totalProfit = 0;
    vector<int> selectedJobs;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;  // Assign this job to this slot
                totalProfit += jobs[i].profit;  // Add this job's profit to the total profit
                selectedJobs.push_back(jobs[i].id); // Store the job id for output
                break;
            }
        }
    }

    // Print the result
    cout << "Total Profit: " << totalProfit << endl;
    cout << "Selected Job IDs: ";
    for (int id : selectedJobs) {
        cout << id << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs;
    cout << "Enter job details (ID, Deadline, Profit) for each job:" << endl;
    for (int i = 0; i < n; i++) {
        int id, deadline, profit;
        cin >> id >> deadline >> profit;
        jobs.emplace_back(id, deadline, profit);
    }

    jobScheduling(jobs, n);

    return 0;
}
