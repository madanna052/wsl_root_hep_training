void task5_invariant_mass(){
    //任务5：读取TTree，计算两个μ子的不变质量，绘制不变质量谱
    TFile *fin = TFile::Open("z_mumu_tree.root");
    TTree *tree = (TTree*)fin->Get("mu_tree");

    double px1,py1,pz1;
    double px2,py2,pz2;
    const double m_mu = 0.1057; //μ子质量 GeV

    tree->SetBranchAddress("px1",&px1);
    tree->SetBranchAddress("py1",&py1);
    tree->SetBranchAddress("pz1",&pz1);
    tree->SetBranchAddress("px2",&px2);
    tree->SetBranchAddress("py2",&py2);
    tree->SetBranchAddress("pz2",&pz2);

    //直方图：不变质量，范围70~110GeV
    TH1D *h_mass = new TH1D("h_mass","Dimuon invariant mass; M [GeV]; Entries",100,70,110);

    Long64_t nEntries = tree->GetEntries();
    cout << "总事例数：" << nEntries << endl;

    for(Long64_t i=0; i<nEntries; i++){
        tree->GetEntry(i);
        //计算两个μ子的能量
        double e1 = sqrt(px1*px1 + py1*py1 + pz1*pz1 + m_mu*m_mu);
        double e2 = sqrt(px2*px2 + py2*py2 + pz2*pz2 + m_mu*m_mu);

        //总四动量
        double totalE = e1 + e2;
        double totalPx = px1 + px2;
        double totalPy = py1 + py2;
        double totalPz = pz1 + pz2;

        //不变质量公式
        double mass_sq = totalE*totalE - (totalPx*totalPx + totalPy*totalPy + totalPz*totalPz);
        if(mass_sq < 0) continue; //跳过负数，防止NaN报错
        double inv_mass = sqrt(mass_sq);

        h_mass->Fill(inv_mass);
    }

    TCanvas *c = new TCanvas("c5","Invariant Mass Canvas");
    h_mass->Draw();
    h_mass->Fit("gaus"); //高斯拟合Z峰
    c->SaveAs("task5_invariant_mass.png");

    fin->Close();
    cout << "任务5完成，不变质量图保存为 task5_invariant_mass.png" << endl;
}
