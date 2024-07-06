// Run by Node.js
const readline = require('readline');

(async () => {
	let rl = readline.createInterface({ input: process.stdin });
	let N; // 지인의 수
	for await (const line of rl) {
		const inputs = line.trim().split(' ').map((e) => +e);
		if(!N){
			[N] = inputs;
		}
		else{
			const scores = inputs;
			const result = inputs.reduce((prev,cur) => (prev+cur),0);
			
			console.log(result);
			rl.close();
		}
	}
	
	process.exit();
})();
