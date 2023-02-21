const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', (data) => {
    let nums = data.split(" ").map(el => parseInt(el));
    const ops = ["+", "-", "*", "/"];
    let res = 10000000000;
    for (let i = 0; i < ops.length; ++i) {
        for (let j = 0; j < ops.length; ++j) {
            let arr = [nums[0], ops[i], nums[1], ops[j], nums[2]];
            let valid = true;
            for (let k = 1; k < arr.length; k += 2) {
                if (arr[k] === "*") {
                    const mult = arr.splice(k - 1, 3);
                    arr.splice(k - 1, 0, mult[0] * mult[2]);
                    k -= 2;
                } else if (arr[k] === "/") {
                    const div = arr.splice(k - 1, 3);
                    if (div[0] % div[2] !== 0) { valid = false; }
                    arr.splice(k - 1, 0, div[0] / div[2]);
                    k -= 2;
                } else if (arr[k] === "+") {
                    const add = arr.splice(k - 1, 3);
                    arr.splice(k - 1, 0, add[0] + add[2]);
                    k -= 2;
                } else if (arr[k] === "-") {
                    const sub = arr.splice(k - 1, 3);
                    arr.splice(k - 1, 0, sub[0] - sub[2]);
                    k -= 2;
                }
            }
            if (!valid) {continue;}
            for (let k = 1; k < arr.length; k += 2) {

            }
            if (arr[0] >= 0 && arr[0] < res) {
                res = arr[0];
            }
        }
    }
    console.log(res);
    rl.close();
});