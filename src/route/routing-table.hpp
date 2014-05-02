#ifndef NLSR_ROUTING_TABLE_HPP
#define NLSR_ROUTING_TABLE_HPP

#include <iostream>
#include <utility>
#include <string>
#include <boost/cstdint.hpp>

#include "routing-table-entry.hpp"

namespace nlsr {

class Nlsr;
class NextHop;

class RoutingTable
{
public:
  RoutingTable()
    : m_NO_NEXT_HOP(-12345)
  {
  }
  void
  calculate(Nlsr& pnlsr);

  void
  addNextHop(std::string destRouter, NextHop& nh);

  void
  printRoutingTable();

  void
  addNextHopToDryTable(std::string destRouter, NextHop& nh);

  void
  printDryRoutingTable();

  RoutingTableEntry*
  findRoutingTableEntry(const std::string destRouter);

  void
  scheduleRoutingTableCalculation(Nlsr& pnlsr);

  int
  getNoNextHop()
  {
    return m_NO_NEXT_HOP;
  }

private:
  void
  calculateLsRoutingTable(Nlsr& pnlsr);

  void
  calculateHypRoutingTable(Nlsr& pnlsr);

  void
  calculateHypDryRoutingTable(Nlsr& pnlsr);

  void
  clearRoutingTable();

  void
  clearDryRoutingTable();

  const int m_NO_NEXT_HOP;

  std::list<RoutingTableEntry> m_rTable;
  std::list<RoutingTableEntry> m_dryTable;
};

}//namespace nlsr

#endif //NLSR_ROUTING_TABLE_HPP