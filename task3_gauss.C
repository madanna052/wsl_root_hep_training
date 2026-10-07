void task3_gauss(){
    // 任务3：生成高斯随机数，填充直方图，高斯拟合
    // 模拟CMS Z→μμ不变质量峰，中心91.1876 GeV，宽度2 GeV
    const double mZ = 91.1876;
    const double width = 2.0;

    // 创建一维直方图
    // 参数：名称，标题，bin数目，左边界，右边界
    TH1D *h_mc = new TH1D("h_mc","Z boson mass MC; M [GeV]; Entries",100,80,100);

    // 随机数引擎，固定种子保证每次运行结果一样
    TRandom3 rnd(12345);

    // 循环生成20000个事例
    int N = 20000;
    for(int i=0; i<N; i++){
        // 生成高斯分布随机数，均值mZ，标准差width
        double mass = rnd.Gaus(mZ, width);
        h_mc->Fill(mass); // 填入直方图
    }

    // 创建画布，用来画图
    TCanvas *c = new TCanvas("c","Gaussian fit canvas");
    h_mc->Draw();

    // 高斯拟合，"gaus"是ROOT内置高斯函数
    h_mc->Fit("gaus");

    // 保存图片，自动存png，避免WSL画布一闪消失
    c->SaveAs("task3_gauss.png");

    cout << "任务3运行完成，图片保存为 task3_gauss.png" << endl;
}
