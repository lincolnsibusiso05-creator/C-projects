#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

void print_vec(const std::vector<int>& v, const std::string& label) {
    std::cout << label << ": ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {5, 2, 8, 2, 9, 1, 5, 4, 7, 3};
    print_vec(data, "Original");

    // 1. Non-modifying sequence operations
    int count_2 = std::count(data.begin(), data.end(), 2);
    auto it_find = std::find_if(data.begin(), data.end(), [](int x){ return x > 6; });
    std::vector<int> sub = {9, 1};
    auto it_search = std::search(data.begin(), data.end(), sub.begin(), sub.end());
    
    std::cout << "\n--- Non-modifying ---\n";
    std::cout << "count of 2: " << count_2 << "\n";
    if (it_find != data.end()) std::cout << "find_if >6: " << *it_find << "\n";
    if (it_search != data.end()) std::cout << "search {9,1} found at index: " 
              << std::distance(data.begin(), it_search) << "\n";

    // 2. Modifying sequence operations
    std::vector<int> mod = data;
    std::replace(mod.begin(), mod.end(), 2, 99); // replace 2 with 99
    auto new_end = std::remove(mod.begin(), mod.end(), 99); // remove 99s
    mod.erase(new_end, mod.end()); // actually erase after remove
    std::reverse(mod.begin(), mod.end());
    
    std::cout << "\n--- Modifying ---\n";
    print_vec(mod, "After replace 2->99, remove 99, reverse");

    // 3. Partitioning operations
    std::vector<int> part = data;
    auto part_point = std::partition(part.begin(), part.end(), [](int x){ return x % 2 == 0; });
    std::cout << "\n--- Partitioning ---\n";
    print_vec(part, "Partitioned: evens first");
    std::cout << "Partition point at index: " << std::distance(part.begin(), part_point) << "\n";

    // 4. Sorting operations
    std::vector<int> s1 = data, s2 = data, s3 = data;
    std::sort(s1.begin(), s1.end());
    std::stable_sort(s2.begin(), s2.end());
    std::partial_sort(s3.begin(), s3.begin() + 4, s3.end()); // smallest 4 sorted
    
    std::cout << "\n--- Sorting ---\n";
    print_vec(s1, "sort");
    print_vec(s2, "stable_sort");
    print_vec(s3, "partial_sort, first 4");

    // 5. Binary search - requires sorted range
    std::vector<int> sorted = s1; // use sorted from above
    bool found_7 = std::binary_search(sorted.begin(), sorted.end(), 7);
    auto lb = std::lower_bound(sorted.begin(), sorted.end(), 5);
    auto ub = std::upper_bound(sorted.begin(), sorted.end(), 5);
    
    std::cout << "\n--- Binary search on sorted ---\n";
    print_vec(sorted, "Sorted data");
    std::cout << "binary_search 7: " << (found_7 ? "true" : "false") << "\n";
    std::cout << "lower_bound 5 at index: " << std::distance(sorted.begin(), lb) << "\n";
    std::cout << "upper_bound 5 at index: " << std::distance(sorted.begin(), ub) << "\n";

    // 6. Merge - requires sorted ranges
    std::vector<int> a = {1, 3, 5, 7};
    std::vector<int> b = {2, 4, 6, 8};
    std::vector<int> merged;
    std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(merged));
    
    std::cout << "\n--- Merge ---\n";
    print_vec(a, "A");
    print_vec(b, "B");
    print_vec(merged, "Merged A+B");

    // 7. Heap operations
    std::vector<int> heap = {3, 1, 4, 1, 5, 9};
    std::make_heap(heap.begin(), heap.end()); // max-heap
    heap.push_back(10);
    std::push_heap(heap.begin(), heap.end());
    std::pop_heap(heap.begin(), heap.end()); // moves max to end
    int max_val = heap.back();
    heap.pop_back(); // remove it
    
    std::cout << "\n--- Heap ---\n";
    print_vec(heap, "Heap after push 10, pop max");
    std::cout << "Popped max value: " << max_val << "\n";

    // 8. Minimum/maximum
    auto [min_it, max_it] = std::minmax_element(data.begin(), data.end());
    int a_val = 15, b_val = 20;
    
    std::cout << "\n--- Min/Max ---\n";
    std::cout << "min_element: " << *min_it << ", max_element: " << *max_it << "\n";
    std::cout << "min(15, 20): " << std::min(a_val, b_val) << "\n";
    std::cout << "max(15, 20): " << std::max(a_val, b_val) << "\n";

    return 0;
}-


