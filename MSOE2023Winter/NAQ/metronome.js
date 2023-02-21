const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', (data) => {
    let a = parseFloat(data);
    console.log(`${(a / 4).toFixed(2)}`);
    rl.close();
});