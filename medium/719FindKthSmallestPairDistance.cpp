//
// Created by 宋峰 on 2021/3/17.
//
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Heap {
public:
    int size = 0;
    vector<int> mem;

    void insert(int x) {
        mem.push_back(x);
        adjust1();
        size += 1;
    }

    void adjust1() {
        int t = mem.size() - 1;
        while (t > 0) {
            int f = (t - 1) / 2;
            if (mem[t] < mem[f]) {
                int tmp = mem[f];
                mem[f] = mem[t];
                mem[t] = tmp;
                t = f;
            } else {
                break;
            }
        }
    }

    void delete_head() {
        int tmp = mem[0];
        mem[0] = mem[mem.size() - 1];
        mem[mem.size() - 1] = tmp;
        mem.pop_back();
        size -= 1;
        adjust2();
    }

    void adjust2() {
        int t = 0;
        while (t < mem.size() / 2) {
            int max = t;
            int l = 2 * t + 1;
            int r = 2 * t + 2;
            if (l < mem.size() && mem[l] < mem[max]) {
                max = l;
            }
            if (r < mem.size() && mem[r] < mem[max]) {
                max = r;
            }
            if (max != t) {
                int tmp = mem[t];
                mem[t] = mem[max];
                mem[max] = tmp;
                t = max;
            } else {
                break;
            }
        }
    }
};

class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums.front();
        int smallestDis = 0;
        while (left <= right) {
            int mid = (right + left) / 2;
            int count = 0;
            int begin = 0;
            for (int i = 0; i < nums.size(); i++) {
                int end = begin;
                while (end < nums.size() && nums[end] - nums[i] <= mid) {
                    end++;
                }
                int dis = 0;
                dis = (end - begin) * (end - begin - 1) / 2 + (begin - i) * (end - begin);
                begin = end;
                if (count + dis >= k) {
                    count += dis;
                    break;
                } else {
                    count += dis;
                }
            }
            if (count >= k) {
                smallestDis = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return smallestDis;
    }

    int smallestDistancePair2(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        vector<int> nums2;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = 1;
                nums2.push_back(nums[i]);
            } else {
                map[nums[i]] += 1;
            }
        }
        Heap heap;
        unordered_map<int, int> map2;
        for (int i = 0; i < nums2.size(); i++) {
            if (map[nums2[i]] > 1) {
                if (map2.find(0) == map2.end()) {
                    heap.insert(0);
                    map2[0] = (map[nums2[i]] * (map[nums2[i]] - 1) / 2);
                } else {
                    map2[0] += (map[nums2[i]] * (map[nums2[i]] - 1) / 2);
                }
            }
        }

        if (map2.find(0) != map2.end() && map2[0] >= k) {
            return 0;
        }

        if (map2.find(0) != map2.end()) {
            k -= map2[0];
            heap.delete_head();
        }

        sort(nums2.begin(), nums2.end());

        for (int d = 1; d < nums2.size(); d++) {
            for (int l = 0; l + d < nums2.size(); l++) {
                int ab = abs(nums2[l] - nums2[l + d]);
                if (map2.find(ab) == map2.end()) {
                    heap.insert(ab);
                    map2[ab] = map[nums2[l]] * map[nums2[l + d]];
                } else {
                    map2[ab] += map[nums2[l]] * map[nums2[l + d]];
                }
            }
            if (map2[heap.mem[0]] >= k) {
                return heap.mem[0];
            } else {
                k -= map2[heap.mem[0]];
                map2.erase(map2.find(heap.mem[0]));
                heap.delete_head();
            }
        }

        while (heap.size > 0 && k > 0) {
            int head = heap.mem[0];
            if (map2[head] >= k) {
                return head;
            } else {
                k -= map2[head];
                heap.delete_head();
            }
        }
        return heap.mem[0];
    }

    int smallestDistancePair1(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front(), smallestDis = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = 0, rt = 0;
            for (int i = 0; i < (int) nums.size(); i++) {
                int rt2 = rt;
                while (rt2 < (int) nums.size() and nums[rt2] - nums[i] <= mid) {
                    rt2++;
                }
                rt2--;
                int dis = ((rt2 - i + 1) * (rt2 - i + 2)) / 2 - ((rt - i + 1) * (rt - i + 2)) / 2 - (rt2 - rt);
                rt = rt2;
                if (count + dis >= k) {
                    count += dis;
                    break;
                } else count += dis;

            }
            if (count >= k) {
                smallestDis = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return smallestDis;
    }
};