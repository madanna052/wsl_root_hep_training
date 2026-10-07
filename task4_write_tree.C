void task4_write_tree(){
    // 任务4：写入TTree，模拟Z→μμ，保存两个μ子动量px,py,pz
    TFile *fout = new TFile("z_mumu_tree.root","RECREATE");
    TTree *tree = new TTree("mu_tree","Z to mumu events");

    // 定义变量，存储两个μ子的动量分量
    double px1,py1,pz1;
    double px2,py2,pz2;

    // 创建分支Branch，把变量绑定到TTree
    tree->Branch("px1",&px1,"px1/D");
    tree->Branch("py1",&py1,"py1/D");
    tree->Branch("pz1",&pz1,"pz1/D");
    tree->Branch("px2",&px2,"px2/D");
    tree->Branch("py2",&py2,"py2/D");
    tree->Branch("pz2",&pz2,"pz2/D");

    TRandom3 rng(12345);
    const double mZ = 91.1876;
    const double m_mu = 0.1057; // μ子质量 GeV
    int Nevents = 20000; // 生成2万个事例

    for(int i=0;i<Nevents;i++){
        // 生成Z的质量，高斯分布
        double m_gen = rng.Gaus(mZ,2.0);
        // 两体衰变，计算衰变产物动量大小
        double p_dec = sqrt( pow(m_gen/2,2) - m_mu*m_mu );
        // 随机角度
        double theta = rng.Uniform(0,TMath::Pi());
        double phi = rng.Uniform(0,2*TMath::Pi());
        double cth = cos(theta);
        double sth = sin(theta);

        // 第一个μ子动量
        px1 = p_dec * sth * cos(phi);
        py1 = p_dec * sth * sin(phi);
        pz1 = p_dec * cth;
        // 第二个μ子，动量反向，动量守恒
        px2 = -px1;
        py2 = -py1;
        pz2 = -pz1;

        tree->Fill(); // 把当前这组数据存入TTree
    }
    tree->Write();
    fout->Close();
    cout << "任务4：TTree写入完成，文件 z_mumu_tree.root 已生成" << endl;
}
