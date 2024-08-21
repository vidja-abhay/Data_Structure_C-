#include <bits/stdc++.h>
using namespace std;

// Class to represent an activity
class Activity {
public:
    int start;
    int finish;

    Activity(int s, int f) : start(s), finish(f) {}

    // Static function to compare two activities based on their finish time
    static bool compare(Activity a1, Activity a2) {
        return a1.finish < a2.finish;
    }
};

// Class to handle the Activity Selection logic
class ActivitySelector {
public:
    vector<Activity> activities;

    // Constructor to initialize activities
    ActivitySelector(vector<Activity> &acts) {
        activities = acts;
    }

    // Function to perform the activity selection
    void selectActivities() {
        int n = activities.size();

        // Sort activities based on finish time
        sort(activities.begin(), activities.end(), Activity::compare);

        cout << "Selected Activities: " << endl;

        // The first activity is always selected
        int lastSelectedIndex = 0;
        cout << "(" << activities[lastSelectedIndex].start << ", " << activities[lastSelectedIndex].finish << ")" << endl;

        // Consider the rest of the activities
        for (int i = 1; i < n; i++) {
            // If this activity has a start time greater than or equal to the finish time of the last selected activity, select it
            if (activities[i].start >= activities[lastSelectedIndex].finish) {
                cout << "(" << activities[i].start << ", " << activities[i].finish << ")" << endl;
                lastSelectedIndex = i;
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities;

    cout << "Enter the start and finish time of each activity:" << endl;
    for (int i = 0; i < n; i++) {
        int start, finish;
        cin >> start >> finish;
        activities.emplace_back(start, finish);
    }

    ActivitySelector selector(activities);
    selector.selectActivities();

    return 0;
}
