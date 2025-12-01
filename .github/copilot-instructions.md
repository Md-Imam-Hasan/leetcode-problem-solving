# Copilot Instructions for LeetCode Problem Solving Repository

## Project Overview

This is a **personal LeetCode problem-solving collection** in C++ organized by problem categories and contest participation. It is **not a production codebase**—each file is an isolated solution to a specific algorithmic problem.

**Structure:**
- Root: Individual LeetCode problems numbered by problem ID (e.g., `3-longest-substring-without-repeating-characters.cpp`)
- `/System & Software Design/`: System design problems (e.g., LRU Cache implementations)
- `/DCC February 2025/`, `/DCC January 2025/`: Daily Coding Challenge problems from specific months
- `/Biweekly Contest 148/`, `/Weekly Contest 431/`: Contest-specific solutions
- `/LeetCode 75/`: Solutions from the LeetCode 75 curated list
- `/biweekly-contest-133/`: Older contest solutions

## C++ Code Patterns & Conventions

### Standard Includes and Aliases
All files consistently use:
```cpp
#include <bits/stdc++.h>  // Competitive programming header (includes all STL)
using namespace std;
```

Exception: System design problems like `Q1. LRU Cache.cpp` may use minimal headers and manual class definitions.

### Solution Class Pattern
Most LeetCode solutions follow this structure:
```cpp
class Solution {
public:
    // Method signature matches LeetCode interface
    // e.g., vector<vector<string>> groupAnagrams(vector<string> &strs)
};
```

**Key observation:** Solutions are designed to be copy-pasted directly into LeetCode's online judge—they may lack main functions or comprehensive testing.

### Common Algorithms & Data Structures Used

- **Sliding Window:** `3-longest-substring-without-repeating-characters.cpp`, `567-permutation-in-string.cpp`
- **Two-Pointer Technique:** `11-container-with-most-water.cpp`, `167-two-sum-ii-input-array-is-sorted.cpp`
- **Hash Maps:** `49-group-anagrams.cpp`, `2349-design-a-number-container-system.cpp`
- **Stacks:** `20-valid-parentheses.cpp`, `155-min-stack.cpp`, `84-largest-rectangle-in-histogram.cpp`
- **Binary Search:** `704-binary-search.cpp`, `875-koko-eating-bananas.cpp`
- **Monotonic Stacks/Deques:** `739-daily-temperatures.cpp`, `853-car-fleet.cpp`
- **Linked Lists & Trees:** Both classic implementations and variations

### Example: Sliding Window Pattern
From `3-longest-substring-without-repeating-characters.cpp`:
- Maintain a window with `left` and `right` pointers
- Use `unordered_map<char, int>` to track character positions
- Expand window by incrementing `right`, shrink by moving `left`
- Track max result during expansion

## What NOT to Assume

- **No build infrastructure:** No Makefile, CMakeLists.txt, or main() functions in most files
- **No testing framework:** Solutions are validated against LeetCode's online judge, not local unit tests
- **No CI/CD pipelines:** No GitHub Actions or workflows to maintain
- **No dependencies to manage:** Pure C++ STL, no external libraries
- **No performance benchmarks:** Timing comes from LeetCode's judge

## How to Help with This Codebase

1. **Review or refactor a solution:** Improve time/space complexity, add comments for unclear logic
2. **Add new solutions:** Follow the existing class pattern and naming convention (problem-ID or problem-name)
3. **Organize contest submissions:** Place solutions in their respective contest/month folders
4. **Document algorithmic insights:** Add brief comments explaining non-obvious approaches

When modifying files, preserve the LeetCode interface (exact method signatures) so solutions remain copy-paste ready.

## File Naming Conventions

- **Standard:** `{problem-id}-{kebab-case-title}.cpp` (e.g., `11-container-with-most-water.cpp`)
- **C++ variant:** Some use `.c++` extension (e.g., `2000-reverse-prefix-of-word.c++`)
- **System Design:** `Q1. LRU Cache.cpp` (descriptive, numbered by question)
- **Contest:** `{contest-name}/{problem-name-or-letter}.cpp`

## Code Style Notes

- **Minimal comments:** Solutions prioritize brevity (typical of competitive programming)
- **Variable naming:** Short names common (`l`, `r`, `mp`, `ans`), consistent within each algorithm
- **Optimization focus:** Solutions optimize for time/space complexity, not readability

