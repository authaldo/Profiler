/**
 * @file Profiler.hpp.h
 * @author ottojo
 * @date 1/23/21
 * Description here TODO
 */

#ifndef PROFILER_PROFILER_HPP
#define PROFILER_PROFILER_HPP

#include <filesystem>
#include <mutex>
#include <string>
#include <vector>

#include "TraceEvent.hpp"
#include "TraceEventFile.hpp"

class ScopeEvent;
class DurationEvent;

class Profiler {
    // Friend classes used to hide submitEvent from user, who should use public functions of Profiler instead
    friend class ScopeEvent;
    friend class DurationEvent;

  public:
    Profiler(std::string name, std::filesystem::path outputPath);

    ~Profiler();

    void setProcessName(const std::string &processName);

    void setThreadName(const std::string &threadName);

    void submitInstantEvent(const std::string &eventName, Scope scope);

    void submitCounterEvent(const std::string &counterName, const std::map<std::string, int> &data);

    void save();

  private:
    void submitEvent(const TraceEvent &event);

    std::string name;
    std::filesystem::path outputPath;
    TraceEventFile eventFile;
    std::mutex eventListMutex;
};

#endif // PROFILER_PROFILER_HPP