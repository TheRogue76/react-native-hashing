interface IRNHashing {
  sha256: (input: string) => string;
  md5: (input: string) => string;
  sha1: (input: string) => string;
  sha3: (input: string) => string;
}

declare global {
  const RNHashing: IRNHashing;
}

export const sha256 = RNHashing.sha256;
export const md5 = RNHashing.md5;
export const sha1 = RNHashing.sha1;
export const sha3 = RNHashing.sha3;
