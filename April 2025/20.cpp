class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0], fast = arr[0];
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);
        fast = arr[0];
        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }
        return slow;
    }
};


2)
class Solution {
  public:
    int findDuplicate(vector<int>& a) {
        int s = a[0], f = a[0];
        do { 
            s = a[s];
            f = a[a[f]];
        } while (s != f);
        f = a[0];
        while (s != f) { 
            s = a[s];
            f = a[f];
        }
        return s;
    }
};


3)
class Solution {
  public:
    int findDuplicate(vector<int>& a) {
        for (int i = 0; i < a.size(); i++) {
            int idx = abs(a[i]);
            if (a[idx] < 0) return idx;
            a[idx] = -a[idx];
        }
        return -1;
    }
};


4)
class Solution {
  public:
    int findDuplicate(vector<int>& a) {
        unordered_set<int> s;
        for (int x : a)
            if (!s.insert(x).second) return x;
        return -1;
    }
};
