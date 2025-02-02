#pragma once

#include "inputs_preparation/tensor_utils.hpp"
#include "utils/utils.hpp"

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace inputs {

struct InputDescr {
    TensorDescription tensor_descr;
    std::vector<std::string> files;
    std::vector<float> mean = {0.f, 0.f, 0.f};
    std::vector<float> scale = {1.f, 1.f, 1.f};
};

using InputsInfo = std::map<std::string, InputDescr>;

int get_batch_size(const InputsInfo& inputs_info);

void set_batch_size(InputsInfo& inputs_info, int batch_size);

InputsInfo get_inputs_info(const std::map<std::string, std::vector<std::string>>& input_files,
                           const std::vector<TensorDescription>& model_inputs,
                           const std::string& layout_string,
                           const std::string& shape_string,
                           const std::string& mean_string,
                           const std::string& scale_string);

std::vector<std::vector<TensorBuffer>> get_input_tensors(const InputsInfo& inputs_info,
                                                         int batch_size,
                                                         int tensors_num = 1);
}  // namespace inputs
