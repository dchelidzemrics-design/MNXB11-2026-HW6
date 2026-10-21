#include "MovingObject.h"
#include <TFile.h>
#include <TTree.h>
#include <TH2D.h>
#include <TCanvas.h>

void read()
{
	TFile * file = new TFile("tree_file.root", "READ");

	if (!file || file->IsZombie())
	{
		return;
	}

	TTree * tree = (TTree*)file->Get("tree");

	if (!tree)
	{
		return;
	}

	MovingObject * object = nullptr;

	tree->SetBranchAddress("object", &object);

	Long64_t nEntries = tree->GetEntries();

	TH2D * hist = new TH2D("hist", "Velocity components; v_{x} (m/s); v_{y} (m/s)",
	100, -1.5, 1.5,
	100, -1.5, 1.5);

	for (Long64_t i = 0; i < nEntries; ++i)
	{
		tree->GetEntry(i);

		hist->Fill(object->Vx(), object->Vy());
	}

	TCanvas * c1 = new TCanvas("c1", "Velocity components", 800, 600);
	
	hist->Draw("COLZ");

	c1->SaveAs("velocity_components.pdf");

	TH2D * hist2 = new TH2D("hist2", "Selected velocities; v_{z} (m/s); v_{xy} (m/s)", 
	100, -1.5, 1.5,
	100, 0.0, 1.5);

	TCanvas * c2 = new TCanvas("c2", "Selected velocities", 800, 600);

	tree->Draw("sqrt(fVx * fVx + fVy * fVy):fVz>>hist2",
		 "sqrt(fVx * fVx + fVy * fVy + fVz * fVz) > 0.50");

	c2->SaveAs("selected_velocities.pdf");
}


