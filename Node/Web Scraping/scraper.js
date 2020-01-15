const puppeteer = require('puppeteer');

async function scrapeProduct(url) {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();
    await page.goto(url);

    const [el] = await page.$x('//*[@id="imgBlkFront"]');
    const src = await el.getProperty('src');
    const image = await src.jsonValue();

    // Selecting the title
    const [el1] = await page.$x('//*[@id="productTitle"]');
    const txt = await el1.getProperty('textContent');
    const title = await txt.jsonValue();

    // Selecting price
    const [el2] = await page.$x('//*[@id="buyNewSection"]/a/h5/div/div[2]/div/span[2]');
    const txt2 = await el2.getProperty('textContent');
    const price = await txt2.jsonValue();

    console.log({image, title, price});


    

    browser.close();
}

scrapeProduct('https://www.amazon.com/Black-Swan-Improbable-Robustness-Fragility/dp/081297381X/ref=sr_1_2?keywords=black+swan&qid=1578720702&sr=8-2');