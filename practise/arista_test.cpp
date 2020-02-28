#include <algorithm>
#include <iostream>
#include <vector>

struct hdr_t {
  int offset;
  int more_frags;
  int len;
};

struct packet {
  hdr_t       header;
  std::string payload;
  packet*     next;
};

// comparator for packet
bool CompareUsingOffset(const packet* left_packet, const packet* right_packet) {
  return left_packet->header.offset < right_packet->header.offset;
}
std::vector<packet*> packet_list;

void RecvFragPacket(packet* pack_p) {
  // emplace the frag_packet_list
  packet_list.emplace_back(pack_p);
}

packet* ConstructFullPaket() {
  std::sort(packet_list.begin(), packet_list.end(), CompareUsingOffset);
  packet* unfrag_packet_p = new packet();
  // merge the sorted list of fragmeneted packets in one
  for (const auto& packet_p : packet_list) {
    unfrag_packet_p->header.len += packet_p->header.len;
    unfrag_packet_p->payload += packet_p->payload;
  }
  return unfrag_packet_p;
}

int main() {
  freopen("../input.txt", "rt", stdin);
  int n;
  scanf("%d", &n);
  printf("%s: n = %d\n", __func__, n);
  for (int i = 0; i < n; ++i) {
    packet*     packet_p = new packet();
    int         offset, more_frags, len;
    std::string payload;
    scanf("%d %d %d", &offset, &more_frags, &len);
    std::cin >> payload;
    packet_p->header.offset     = offset;
    packet_p->header.more_frags = more_frags;
    packet_p->header.len        = len;
    packet_p->payload           = payload;
    printf("%s: offset = %d more_frags = %d len = %d payload = %s\n", __func__, offset, more_frags, len,
           payload.c_str());
    RecvFragPacket(packet_p);
  }
  packet* final_packet = ConstructFullPaket();
  printf("%s: final packet = %s\n", __func__, final_packet->payload.c_str());
  return 0;
}
