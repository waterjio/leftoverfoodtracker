// Jovanni
// CPSC 121L-19
// 4/19/24
// doctorjovas@csu.fullerton.edu
// @waterjio

#ifndef LEFTOVER_REPORT_H
#define LEFTOVER_REPORT_H


#include <map>
#include <string>
#include <vector>


#include "leftover_record.h"


class LeftoverReport {
 public:
  LeftoverReport(const std::vector<LeftoverRecord> &leftover_records);

  std::vector<std::string> MostCommonLeftover() const;
  std::vector<std::string> MostCostlyLeftoverProducingMeals() const;
  double TotalCostOfLeftover() const;
  std::vector<std::string> MostCommonLeftoverReasons();
  std::vector<std::string> MostCommonDisposalMechanisms() const;
  std::vector<std::string> SuggestLeftoverReductionStrategies() const;


 private:
  const std::vector<LeftoverRecord> &leftover_records_;
  std::vector<std::string> most_common_leftover_;
  std::vector<std::string> most_costly_leftover_producing_meals_;
  double total_cost_of_leftovers_;
  std::vector<std::string> most_common_leftover_reasons_;
  std::vector<std::string> most_common_disposal_mechanisms_;
  std::vector<std::string> suggested_strategies_to_reduce_leftovers_;
  
};

#endif