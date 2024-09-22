#!/bin/bash

# Get current date and time
current_datetime=$(date +"%d.%m.%Y %H:%M:%S")

# Create the C++ file with the template code
cat <<EOF > sol.cpp
/**
 *    author:  jubair7
 *    created: $current_datetime
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void main_() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    
  }
}

// increasing stack size
void* start_thread(void* arg) {
  void (*func)(void) = (void (*)(void))arg;
  func();
  return nullptr;
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
  pthread_attr_t attr;
  pthread_t thread;
  // Initialize thread attributes
  pthread_attr_init(&attr);
  // Set the stack size for the new thread
  pthread_attr_setstacksize(&attr, stsize);
  // Create a new thread with the specified stack size and run the function
  pthread_create(&thread, &attr, start_thread, (void*)func);
  // Wait for the thread to finish execution
  pthread_join(thread, nullptr);
  // Destroy thread attributes
  pthread_attr_destroy(&attr);
}

int main() {
  run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
  return 0;
}

EOF

echo "C++ file 'sol.cpp' has been created with the current date and time."

