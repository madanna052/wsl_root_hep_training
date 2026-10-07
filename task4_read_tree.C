void task4_read_tree(){
    // 任务4：读取TTree，读取z_mumu_tree.root里面的μ子动量数据
    TFile *fin = TFile::Open("z_mumu_tree.root");
    TTree *tree = (TTree*)fin->Get("mu_tree");

    double px1,py1,pz1;
    double px2,py2,pz2;

    // 把变量和TTree的分支绑定
    tree->SetBranchAddress("px1",&px1);
    tree->SetBranchAddress("py1",&py1);
    tree->SetBranchAddress("pz1",&pz1);
    tree->SetBranchAddress("px2",&px2);
    tree->SetBranchAddress("py2",&py2);
    tree->SetBranchAddress("pz2",&pz2);

    // 创建直方图，看第一个μ子px动量分布
    TH1D *h_px1 = new TH1D("h_px1","muon px distribution; px [GeV]; Entries",100,-50,50);

    Long64_t nEntries = tree->GetEntries();
    cout << "总事例数：" << nEntries << endl;

    // 循环读取每一条事例
    for(Long64_t i=0; i<nEntries; i++){
        tree->GetEntry(i);
        h_px1->Fill(px1);
    }

    TCanvas *c = new TCanvas("c_read","Read TTree canvas");
    h_px1->Draw();
    c->SaveAs("task4_read.png");

    fin->Close();
    cout << "任务4读取完成，图片保存 task4_read.png" << endl;
}
