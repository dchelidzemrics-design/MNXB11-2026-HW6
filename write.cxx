#include "MovingObject.h"
#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>

void write()
{
	MovingObject * object = new MovingObject();
	
	TFile * file = new TFile("tree_file.root", "RECREATE");
	
	TTree * tree = new TTree("tree", "tree");

	tree->Branch("object", &object);

	gRandom->SetSeed(12345);

	const Int_t nMeasurements = 10000;

	Double_t vx, vy, vz;

	for (Int_t i = 0; i < nMeasurements; ++i)
	{
		vx = gRandom->Gaus(0.0, 0.30);
		vy = gRandom->Gaus(0.0, 0.30);
		vz = gRandom->Gaus(0.0, 0.30);

		object->SetVelocity(vx, vy, vz);

		tree->Fill();
	}

	tree->Write();
	file->Close();

	delete object;
	delete file;

}
