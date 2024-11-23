// Jovanni
// CPSC 121L-19
// 4/19/24
// doctorjovas@csu.fullerton.edu
// @waterjio

#ifndef LEFTOVER_TRACKER_H_
#define LEFTOVER_TRACKER_H_

#include <vector>


#include "leftover_record.h"
#include "leftover_report.h"


class LeftoverTracker {
 public:
  LeftoverTracker() {}
  bool AddRecord(const LeftoverRecord &record);
  bool DeleteRecord(const LeftoverRecord &record);
  const std::vector<LeftoverRecord> &GetRecords() const;
  LeftoverReport GetLeftoverReport() const;


 private:
  std::vector<LeftoverRecord> leftover_records_;
};


#endif