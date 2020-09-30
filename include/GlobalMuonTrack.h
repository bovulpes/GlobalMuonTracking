
#ifndef ALICEO2_GLOBALMUONTRACK_H
#define ALICEO2_GLOBALMUONTRACK_H


#include <vector>
#include <TMath.h>
#include "Math/SMatrix.h"

#include "CommonDataFormat/RangeReference.h"
#include "SimulationDataFormat/MCCompLabel.h"
#include "ReconstructionDataFormats/TrackFwd.h"

namespace o2::track {

class GlobalMuonTrack : public o2::track::TrackParCovFwd
{
  using ClusRefs = o2::dataformats::RangeRefComp<4>;
  using SMatrix55 = ROOT::Math::SMatrix<double, 5, 5, ROOT::Math::MatRepSym<double, 5>>;
  using SMatrix5 = ROOT::Math::SVector<Double_t, 5>;

 public:
  GlobalMuonTrack() = default;
  GlobalMuonTrack(const GlobalMuonTrack& t) = default;
  ~GlobalMuonTrack() = default;

  std::uint32_t getROFrame() const { return mROFrame; }
  void setROFrame(std::uint32_t f) { mROFrame = f; }

  void setMatchingChi2(double chi2) { mMatchingChi2 = chi2; }
  double getMatchingChi2() { return mMatchingChi2; }
  void countCandidate() { mNMFTCandidates++; }
  int getNMFTCandidates()  { return mNMFTCandidates; }

  void setBestMFTTrackMatchID(int ID) { mBestMFTTrackMatchID = ID; }
  double getBestMFTTrackMatchID() { return mBestMFTTrackMatchID; }

  void print() const;

 private:
  std::uint32_t mROFrame = 0; ///< RO Frame
  double mMatchingChi2 = 1.0E308;
  int mBestMFTTrackMatchID = -1;
  int mNMFTCandidates = 0; // Number of candidates within search cut


};

}

#endif // ALICEO2_GLOBALMUONTRACK_H
