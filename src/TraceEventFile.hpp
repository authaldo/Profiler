/**
 * @file TraceEventFile.hpp.h
 * @author ottojo
 * @date 1/23/21
 */

#ifndef PROFILER_TRACEEVENTFILE_HPP
#define PROFILER_TRACEEVENTFILE_HPP

#include <nlohmann/json.hpp> // for json_ref, json
#include <string>            // for allocator, string
#include <vector>            // for vector

#include "TraceEvent.hpp" // for TraceEvent

struct TraceEventFile {
    std::vector<TraceEvent> traceEvents;
    std::string displayTimeUnit = "ms";
    nlohmann::json metaData = {{"producedBy", "https://github.com/ottojo/Profiler"}};
};

void to_json(nlohmann::json &j, const TraceEventFile &traceEventFile);

#endif // PROFILER_TRACEEVENTFILE_HPP
