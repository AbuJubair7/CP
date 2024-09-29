// Time start
    auto start = chrono::high_resolution_clock::now();
// Time end
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = end - start;

  // Get memory usage
  struct rusage r_usage;
  getrusage(RUSAGE_SELF, &r_usage);

  // Output the elapsed time and memory usage in megabytes
  debug("Time: ", elapsed.count()) << " seconds\n";
  debug("Memory: ", r_usage.ru_maxrss / 1024.0);