#ifndef OmtfTreeAnalysis_H
#define OmtfTreeAnalysis_H

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "TObjArray.h"

class AnaEvent;
class AnaEff;
class AnaMuonDistribution;
class AnaDataEmul;

namespace edm { class Event; class EventSetup; }

class OmtfTreeAnalysis : public edm::EDAnalyzer {
public:
  OmtfTreeAnalysis(const edm::ParameterSet & cfg);
  virtual ~OmtfTreeAnalysis(){}
  virtual void beginJob();
  virtual void beginRun(const edm::Run&,  const edm::EventSetup& es);
  virtual void analyze(const edm::Event&, const edm::EventSetup& es);
  virtual void endJob();

private:
  TObjArray theHistos;
  edm::ParameterSet theConfig;

  AnaEvent            *theAnaEvent;
  AnaMuonDistribution *theAnaMuonDistribution;
  AnaDataEmul         *theAnaDataEmul;
  AnaEff              *theAnaEff;


}; 

#endif
